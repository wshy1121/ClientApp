#ifndef _MAIN_H_
#define _MAIN_H_

#include <windows.h>
class CBase
{
public:
#ifdef WIN32
	typedef unsigned long pthread_t;
	typedef int  pthread_attr_t;
	typedef CRITICAL_SECTION  pthread_mutex_t;
	typedef int  pthread_mutexattr_t;
#else
	typedef ::pthread_t  pthread_t;
	typedef ::pthread_attr_t  pthread_attr_t;
	typedef ::pthread_mutex_t  pthread_mutex_t;
	typedef ::pthread_mutexattr_t  pthread_mutexattr_t;
#endif
public:
	static int snprintf(char *str, size_t size, const char *format, ...);
	static pthread_t pthread_self(void);
	static int vsnprintf(char *str, size_t size, const char *format, va_list ap);
	static char *strcpy(char *dest, const char *src);
	static int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
	static int usleep(int micro_second);
	static int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
	static int pthread_mutex_lock(pthread_mutex_t *mutex);
	static int pthread_mutex_unlock(pthread_mutex_t *mutex);
	static int backtrace(void **buffer, int size);
	static int close(int fd);
};

#endif
