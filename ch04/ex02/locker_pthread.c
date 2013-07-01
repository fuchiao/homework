#include "locker.h"
#include "main.h"
#include <stdlib.h>
#include "locker_pthread.h"
Ret locker_pthread_lock(Locker* thiz)
{
	PrivInfo* priv = (PrivInfo*) thiz->priv;
	int ret = pthread_mutex_lock(&priv->mutex);
	return ret == 0? RET_OK: RET_FAIL;
}
Ret locker_pthread_unlock(Locker* thiz)
{
	PrivInfo* priv = (PrivInfo*) thiz->priv;
	int ret = pthread_mutex_unlock(&priv->mutex);
	return ret == 0? RET_OK: RET_FAIL;
}
void locker_pthread_destory(Locker* thiz)
{
	PrivInfo* priv = (PrivInfo*) thiz->priv;
	//int ret = pthread_mutex_destory(&priv->mutex);
	return;
}
Locker* locker_pthread_create(void)
{
	Locker* thiz = (Locker*)malloc(sizeof(Locker) + sizeof(PrivInfo));
	if (thiz != NULL) {
		PrivInfo* priv = (PrivInfo*)thiz->priv;
		thiz->lock = locker_pthread_lock;
		thiz->unlock = locker_pthread_unlock;
		thiz->destory = locker_pthread_destory;
		pthread_mutex_init(&(priv->mutex), NULL);
		priv->owner = 0;
		priv->refcount = 0;
	}
	return thiz;
}

