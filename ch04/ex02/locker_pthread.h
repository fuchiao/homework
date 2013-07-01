#include "locker.h"
#include <pthread.h>
typedef struct _PrivInfo
{
	int owner;
	int refcount;
	pthread_mutex_t mutex;
}PrivInfo;
Locker* locker_pthread_create();

