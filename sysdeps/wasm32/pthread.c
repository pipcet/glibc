#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int
pthread_create (pthread_t *thr, const pthread_attr_t *attr,
		void *(*start_routine) (void *), void *arg)
{
  fprintf(stderr, "pthread_create\n");
  return -1;
}

int pthread_attr_init(pthread_attr_t *attr)
{
  return 0;
}
int pthread_attr_destroy(pthread_attr_t *attr)
{
  return 0;
}

int pthread_key_create(pthread_key_t *key, void (*destructor)(void*))
{
  *key = (pthread_key_t)malloc (sizeof (void *));
  return 0;
}

int pthread_key_delete(pthread_key_t key)
{
  free ((void **)key);
  return 0;
}

void *pthread_getspecific(pthread_key_t key)
{
  return *(void **)key;
}
int pthread_setspecific(pthread_key_t key, const void *value)
{
  void *value2 = (void *)value;
  *(void **)key = value2;
  fprintf(stderr, "pthread_setspecific\n");
  return 0;
}

int pthread_mutex_init(pthread_mutex_t *restrict mutex,
		       const pthread_mutexattr_t *restrict attr)
{
  return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
  return 0;
}

int pthread_cond_init(pthread_cond_t *restrict mutex,
		      const pthread_condattr_t *restrict attr)
{
  return 0;
}

int pthread_cond_destroy(pthread_cond_t *cond)
{
  return 0;
}

int pthread_cond_signal(pthread_cond_t *cond)
{
  return 0;
}

int pthread_mutex_lock(pthread_mutex_t *mutex)
{
  return 0;
}
int pthread_mutex_trylock(pthread_mutex_t *mutex)
{
  return 0;
}
int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
  return 0;
}

int pthread_cond_timedwait(pthread_cond_t *restrict cond,
			   pthread_mutex_t *restrict mutex,
			   const struct timespec *restrict abstime)
{
  return -1;
}
int pthread_cond_wait(pthread_cond_t *restrict cond,
		      pthread_mutex_t *restrict mutex)
{
  fprintf(stderr, "pthread_cond_wait\n");
  return -1;
}

int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize)
{
  return -1;
}
int pthread_attr_getstacksize(const pthread_attr_t *attr,
			      size_t *stacksize)
{
  return -1;
}

pthread_t pthread_self(void)
{
  return 1;
}

void pthread_exit(void *retval)
{
  while (1) {}
}

int pthread_detach(pthread_t thread)
{
  fprintf(stderr, "pthread_detach\n");
  return -1;
}


