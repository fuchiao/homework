#ifndef _MAIN_H_
#define _MAIN_H_
#define Ret int
#define RET_OK 0
#define RET_FAIL -1
#define RET_INVALID_PARAMS -2
#define return_if_fail(p) if (!(p)) {printf("%s:%d Warning: "#p" failed.\n", __func__, __LINE__); return;}
#define return_val_if_fail(p, ret) if (!(p)) {printf("%s:%d Warning: "#p" failed.\n", __func__, __LINE__); return (ret);}
#endif
