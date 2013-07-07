#include "locker.h"
#include "locker_pthread.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct {
	int index;
	Locker * lockPtr;
}DList;

DList dlist_create(void * a, void * b, LockerCreateFuncPtr c) {
	DList * ret = malloc(sizeof(DList));
	if (c) {
		ret->index = 0;
		ret->lockPtr = c();
	}
	return *ret;
}
void * consumer(void *args) {
	int delay = 0, i;
	srand(time(NULL));
	while (1) {
		delay = rand() % 4;
		for (i = 0; delay > i; i++) {
			locker_nest_lock(((DList *)args)->lockPtr, 1);
			sleep(1);
			if (((DList *)args)->index > 0) {
				((DList *)args)->index -= 1;
				printf("Consume 1, remaining %d\n", ((DList *)args)->index);
			}
			else {
				printf("Consume nothing, remaining %d\n", ((DList *)args)->index);
			}
		}
		for (; i > 0; i--) {
			sleep(1);
			printf("Consume unlock, remaining %d\n", ((DList *)args)->index);
			locker_nest_unlock(((DList *)args)->lockPtr, 1);
		}
		sleep(1);
	}
}
void * producer(void *args) {
	int delay = 0, i;
	srand(time(NULL));
	while (1) {
		delay = rand() % 4;
		for (i = 0; delay > i; i++) {
			locker_nest_lock(((DList *)args)->lockPtr, 2);
			sleep(1);
			((DList *)args)->index += 1;
			printf("Produce 1, remaining %d\n", ((DList *)args)->index);
		}
		for (; i > 0; i--) {
			sleep(1);
			printf("Produce unlock, remaining %d\n", ((DList *)args)->index);
			locker_nest_unlock(((DList *)args)->lockPtr, 2);
		}
		sleep(1);
	}
}
int main() {
	DList dlist  = dlist_create(NULL, NULL, locker_pthread_create);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, &consumer, (void *)&dlist);
	pthread_create(&t2, NULL, &producer, (void *)&dlist);
	while (1) sleep(1);
	return 0;
}
