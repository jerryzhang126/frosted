#include "frosted.h"


/* ROOT entity ("/")
 *.
 */
static struct fnode FNO_ROOT = {
    .owner = NULL,
    .fname = "/",
    .mask = 0,
    .parent = &FNO_ROOT,
    .children = NULL,
    .next = NULL 
};


/* Table of open files */
#define MAXFILES 10
static struct fnode *filedesc[MAXFILES];


static int filedesc_new(struct fnode *f)
{
    int i;
    for (i = 0; i < MAXFILES; i++) {
        if (filedesc[i] == NULL) {
            filedesc[i] = f;
            return i;
        }
    }
    return NULL; /* XXX: not enough resources! */
}


static const char *path_walk(const char *path)
{
    const char *p = path;

    if (*p == '/') {
        while(*p == '/')
            p++;
        return p;
    }

    while ((*p != '\0') && (*p != '/'))
        p++;

    if (*p == '/')
        p++;

    if (*p == '\0')
        return NULL;

    return p;
}


/* Returns: 
 * 0 = if path does not match
 * 1 = if path is in the right dir, need to walk more
 * 2 = if path is found!
 */

static int path_check(const char *path, const char *dirname)
{

    int i = 0;
    for (i = 0; dirname[i]; i++) {
        if (path[i] != dirname[i])
            return 0;
    }

    if (path[i] == '\0')
        return 2;

    return 1;
}


static struct fnode *_fno_search(const char *path, struct fnode *dir)
{
    struct fnode *cur;
    int check = 0;
    if (dir == NULL) 
        return NULL;

    check = path_check(path, dir->fname);

    /* Does not match, try another item */
    if (check == 0)
        return _fno_search(path, dir->next);

    /* Item is found! */
    if (check == 2)
        return dir;

    /* path is correct, need to walk more */
    return _fno_search(path_walk(path), dir->children);
}

struct fnode *fno_search(const char *path)
{
    struct fnode *cur = &FNO_ROOT;
    return _fno_search(path, cur);
}

struct fnode *fno_create(struct module *owner, const char *name, struct fnode *parent)
{
    struct fnode *fno = kalloc(sizeof(struct fnode));
    int nlen = strlen(name);
    if (!fno)
        return NULL;

    fno->fname = kalloc(nlen + 1);
    if (!fno->fname){
        kfree(fno);
        return NULL;
    }

    memcpy(fno->fname, name, nlen + 1);
    if (!parent) {
        parent = &FNO_ROOT;
    }

    fno->parent = parent;
    fno->next = fno->parent->children;
    fno->parent->children = fno;

    fno->children = NULL;
    fno->owner = owner;
    fno->mask = 0;
    return fno;
}

void fno_unlink(struct fnode *fno)
{
    struct fnode *dir = fno->parent;
    if (dir) {
        struct fnode *child = dir->children;
        while (child) {
            if (child == fno) {
                dir->children = fno->next;
                break;
            }
            if (child->next == fno) {
                child->next = fno->next;
                break;
            }
            child = child->next;
        }
    }
    kfree(fno->fname);
    kfree(fno);
}


sys_open_hdlr(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5)
{
    const char *path = (const char *)arg1;
    struct fnode *f;

    f = fno_search(path);
    if (f == NULL)
        return -1; /* XXX: ENOENT */
    return filedesc_new(f); 
}

sys_close_hdlr(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5)
{
    if (filedesc[arg1] != NULL) {
        filedesc[arg1] = NULL;
        return 0;
    }
    return -1; /* XXX: EINVAL */
}