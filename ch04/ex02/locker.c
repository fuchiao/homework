#include "main.h"
#include "locker.h"
#include "locker_pthread.h"
#include <stdio.h>
Ret locker_lock(Locker* thiz)
{
	return_val_if_fail(thiz != NULL && thiz->lock != NULL, RET_INVALID_PARAMS);
	return thiz->lock(thiz);
}
Ret locker_nest_lock(Locker* thiz, int caller)
{
	Ret ret = RET_OK;
	PrivInfo* priv = (PrivInfo*)thiz->priv;
	if (priv->owner == caller)
	{
		priv->refcount++;
//		printf("%d lock %d times\n", priv->owner, priv->refcount);
	}
	else
	{
		if ((ret = locker_lock(thiz)) == RET_OK)
		{
			priv->refcount = 1;
			priv->owner = caller;
//			printf("%d lock %d times\n", priv->owner, priv->refcount);
		}
	}
	return ret;
}
Ret locker_unlock(Locker* thiz)
{
	return_val_if_fail(thiz != NULL && thiz->unlock != NULL, RET_INVALID_PARAMS);
	return thiz->unlock(thiz);
}
Ret locker_nest_unlock(Locker* thiz, int caller)
{
	Ret ret = RET_OK;
	PrivInfo* priv = (PrivInfo*)thiz->priv;
	
	return_val_if_fail(priv->owner == caller, RET_FAIL);
	priv->refcount--;
//	printf("%d lock %d times\n", priv->owner, priv->refcount);
	if (priv->refcount == 0)
	{
		priv->owner = 0;
		ret = locker_unlock(thiz);
	}


	return ret;
}
void locker_destory(Locker* thiz)
{
	return_if_fail(thiz != NULL && thiz->destory != NULL);
	thiz->destory(thiz);
	return;
}

