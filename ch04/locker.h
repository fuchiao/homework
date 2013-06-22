#include "main.h"
#ifndef _LOCKER_H_
#define _LOCKER_H_
struct _Locker;
typedef struct _Locker Locker;
typedef Ret (*LockerLockFunc) (Locker* thiz);
typedef Ret (*LockerUnlockFunc) (Locker* thiz);
typedef void (*LockerDestoryFunc) (Locker* thiz);
typedef Locker* (*LockerCreateFuncPtr) (void);
struct _Locker
{
	LockerLockFunc lock;
	LockerUnlockFunc unlock;
	LockerDestoryFunc destory;

	char priv[0];
};
#endif

