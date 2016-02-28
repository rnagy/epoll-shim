#ifndef SHIM_SYS_SIGNALFD_H
#define SHIM_SYS_SIGNALFD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <stdint.h>
#include <fcntl.h>
#include <signal.h>

#if 0
#define __NEED_sigset_t

#include <bits/alltypes.h>
#endif

#define SFD_CLOEXEC O_CLOEXEC
#define SFD_NONBLOCK O_NONBLOCK

int signalfd(int, const sigset_t *, int);

struct signalfd_siginfo {
	uint32_t  ssi_signo;
	int32_t   ssi_errno;
	int32_t   ssi_code;
	uint32_t  ssi_pid;
	uint32_t  ssi_uid;
	int32_t   ssi_fd;
	uint32_t  ssi_tid;
	uint32_t  ssi_band;
	uint32_t  ssi_overrun;
	uint32_t  ssi_trapno;
	int32_t   ssi_status;
	int32_t   ssi_int;
	uint64_t  ssi_ptr;
	uint64_t  ssi_utime;
	uint64_t  ssi_stime;
	uint64_t  ssi_addr;
	uint16_t  ssi_addr_lsb;
	uint8_t   pad[128-12*4-4*8-2];
};

extern int epoll_shim_close(int fd);
extern ssize_t epoll_shim_read(int fd, void *buf, size_t nbytes);
#define read epoll_shim_read
#define close epoll_shim_close

#ifdef __cplusplus
}
#endif

#endif
