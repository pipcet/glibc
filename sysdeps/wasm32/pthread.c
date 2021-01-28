#include <pthread.h>

int
pthread_create (pthread_t *thr, const pthread_attr_t *attr,
		void *(*start_routine) (void *), void *arg)
{
  return -1;
}
