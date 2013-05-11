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
	temp->data = (void *)value;
	printf("insert %d\n", (int)temp->data);
	struct _Node *currPtr;

	if (*headPtr == NULL) {
		*headPtr = temp;
	}
	else {
		temp->nextPtr = *headPtr;
		temp->prevPtr = NULL;
		*headPtr = temp;
	}
}
int print_string(void * data) {
	printf("%s ", (char *)data);
	return 0;
}
int print_int(void * data) {
	printf("%d ", (int)data);
	return 0;
}
void list (struct _Node * headPtr, PrintFuncPtr print) {
	//print data in order
	struct _Node * currPtr = headPtr;
	while (currPtr != NULL) {
		print(currPtr->data);
		currPtr = currPtr->nextPtr;
	}
	printf("\n");
}
void find_max (void *max, void *data) {
	if (*(int *)max < (int)data)
		*(int *)max = (int)data;
}
void summarize (void *sum, void *data) {
	*(int *)sum += (int)data;
}
void foreach (struct _Node *headPtr, VisitFunc visit, void * ctx) {
	//for refactoring
	struct _Node * currPtr = headPtr;
	while (currPtr != NULL) {
		visit(ctx, currPtr->data);
		currPtr = currPtr->nextPtr;
	}
}
