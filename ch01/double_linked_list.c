#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "double_linked_list.h"
struct _Node {
	void * data;
	struct _Node * prevPtr;
	struct _Node * nextPtr;
};
void insert (struct _Node ** headPtr, void * value) {
	struct _Node *temp = malloc(sizeof(struct _Node));
	temp->data = (void *)*((long int *)value);
	printf("insert %ld\n", (long int)temp->data);
	struct _Node *currPtr;

	if (*headPtr == NULL) {
		*headPtr = temp;
	}
	else {
		//compare, then insert
		currPtr = *headPtr;
		while (currPtr->nextPtr != NULL) {
			if ((long int)currPtr->data > *((long int *)value)) {
				break;
			}
			currPtr = currPtr->nextPtr;
		}
		if ((long int)currPtr->data > *((long int *)value)) {
			temp->prevPtr = currPtr->prevPtr;
			currPtr->prevPtr = temp;
			temp->nextPtr = currPtr;
			if (temp->prevPtr != NULL)
				temp->prevPtr->nextPtr = temp;
		}
		else {
			currPtr->nextPtr = temp;
			temp->prevPtr = currPtr;
		}
		if ((*headPtr)->prevPtr != NULL)
			*headPtr = (*headPtr)->prevPtr;
	}
}
int print_string(void * data) {
	printf("%s\n", (char *)data);
	return 0;
}
int print_int(void * data) {
	printf("%ld\n", (long int)data);
	return 0;
}
void list (struct _Node * headPtr, PrintFuncPtr print) {
	//print data in order
	struct _Node * currPtr = headPtr;
	while (currPtr != NULL) {
		print(currPtr->data);
		currPtr = currPtr->nextPtr;
	}
}
void find_max (void *max, void *data) {
	//printf("%ld\n", (long int) data);
	//if ((long int *)max < (long int)data)
	//	*max = (long int)data;
}
void summarize (void *sum, void *data) {
	//printf("%ld\n", (long int) data);
	//*sum = (long int *)sum + (long int)data;
}
void foreach (struct _Node *headPtr, VisitFunc visit, void * ctx) {
	//for refactoring
	struct _Node * currPtr = headPtr;
	while (currPtr != NULL) {
		visit(ctx, currPtr->data);
		currPtr = currPtr->nextPtr;
	}
}
