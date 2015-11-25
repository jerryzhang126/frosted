/* sys/poll.h

   Copyright 2000, 2001, 2006, 2011 Red Hat, Inc.

   This file is part of Cygwin.

   This software is a copyrighted work licensed under the terms of the
   Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
   details. */

#ifndef _SYS_POLL_H
#define _SYS_POLL_H

#include <sys/cdefs.h>
#include <sys/types.h>
#include <signal.h>

__BEGIN_DECLS

/* defined in frosted_api.h */
#ifndef __frosted__
#define POLLIN  1       /* Set if data to read. */
#define POLLPRI 2       /* Set if urgent data to read. */
#define POLLOUT 4       /* Set if writing data wouldn't block. */
#define POLLERR   8     /* An error occured. */
#define POLLHUP  16     /* Shutdown or close happened. */
#define POLLNVAL 32     /* Invalid file descriptor. */
#endif

#define NPOLLFILE 64    /* Number of canonical fd's in one call to poll(). */

/* The following values are defined by XPG4. */
#define POLLRDNORM POLLIN
#define POLLRDBAND POLLPRI
#define POLLWRNORM POLLOUT
#define POLLWRBAND POLLOUT

// XXX Defined in frosted_api.h
//struct pollfd {
//  int fd;
//  short events;
//  short revents;
//};

typedef unsigned int nfds_t;

extern int poll __P ((struct pollfd *fds, nfds_t nfds, int timeout));
extern int ppoll __P ((struct pollfd *fds, nfds_t nfds,
		       const struct timespec *timeout_ts,
		       const sigset_t *sigmask));

__END_DECLS

#endif /* _SYS_POLL_H */
