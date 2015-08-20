#include "frosted.h"
#define IDLE() while(1){do{}while(0);}

/* The following needs to be defined by
 * the application code
 */
extern void init(void *arg);

static int (*_klog_write)(int, const void *, unsigned int) = NULL;
    

void klog_set_write(int (*wr)(int, const void *, unsigned int))
{
    _klog_write = wr;
}

int klog_write(int file, char *ptr, int len)
{
    if (_klog_write) {
        _klog_write(file, ptr, len);
    }
    return len;
}

void frosted_init(void)
{
    ktimer_init();
    SystemInit(); /* SystemInit() -> Board_SystemInit() */
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 1000);

    syscalls_init();
    vfs_init();
    kernel_task_init();
    irq_init();
    frosted_scheduler_on();
}

static void ktimer_test(uint32_t time, void *arg)
{
    klog(LOG_INFO, "Timer expired!!\n");
}

void frosted_kernel(void)
{
    volatile int ret = 0;
    int ttt = 0;
    
    /* Create "init" task */
    klog(LOG_INFO, "Starting Init task\n");
    if (task_create(init, (void *)0, 2) < 0)
        IDLE();

    ktimer_add(1000, ktimer_test, NULL);

    while(1) {
        if (!ttt && (jiffies > 500)) {
            ttt++;
        }
        /* This is the kernel main loop */   
    }
}

/* OS entry point */
void main(void) 
{
    frosted_init();
    frosted_kernel(); /* never returns */
}
