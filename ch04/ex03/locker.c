#include "main.h"
#include "locker.h"
#include <stdio.h>
Ret locker_lock(Locker* thiz)
{
	return_val_if_fail(thiz != NULL && thiz->lock != NULL, RET_INVALID_PARAMS);
	return thiz->lock(thiz);
}
Ret locker_unlock(Locker* thiz)
{
	return_val_if_fail(thiz != NULL && thiz->unlock != NULL, RET_INVALID_PARAMS);
	return thiz->unlock(thiz);
}
void locker_destory(Locker* thiz)
{
	return_if_fail(thiz != NULL && thiz->destory != NULL);
	thiz->destory(thiz);
	return;
}

