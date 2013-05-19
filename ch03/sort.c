#include <stdio.h>
#include "sort.h"
int cmp(void * a, void * b) {
	return *(int *)a - *(int *)b;
}
int cmp_reverse(void *a, void *b) {
	return *(int *)b - *(int *)a;
}
void swap(void ** a, void ** b) {
	void * tmp = *a;
	*a = *b;
	*b = tmp;
}
void merge_sort(void ** ary, int size, DataCmpFunc cmpFunc) {

}
void quick_sort(void ** ary, int lbound, int rbound, DataCmpFunc cmpFunc) {
	int mid, i = lbound, j = rbound, k = lbound;
	if (lbound < rbound) {
		mid = (int)((lbound + rbound)/2);
		if (cmpFunc(ary[k], ary[mid]))
	}
}
void bubble_sort(void ** ary, int size, DataCmpFunc cmpFunc) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (cmpFunc(ary[i], ary[j]) > 0)
				swap(ary + i, ary + j);
		}
	}
}
