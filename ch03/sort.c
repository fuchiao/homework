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
void quick_sort(void ** ary, int size, DataCmpFunc cmpFunc) {
	int mid = (int)(size/2), i = 0, j = size - 1;
	while (i < j) {
		if (cmpFunc(ary[i], ary[mid]) > 0)
			i++;
		if (cmpFunc(ary[mid], ary[j]) > 0)
			j--;
		if (cmpFunc(ary[i], ary[mid]) < 0) {
			if (cmpFunc(ary[mid], ary[j]) < 0)
				swap(ary + i, ary + j);
			else if (j == mid) {
				swap(ary + i, ary + mid);
				mid = i;
				j--;
			}
		}
		if (cmpFunc(ary[j], ary[mid]) > 0) {
			if (cmpFunc(ary[mid], ary[i]) > 0)
				swap(ary + i, ary + j);
			else if (i == mid) {
				swap(ary + j, ary + mid);
				mid = j;
				i++;
			}
		}
	}
	if (1 < mid)
		quick_sort(ary, mid, cmpFunc);
	if (size - mid - 1 > 1)
		quick_sort(ary + mid + 1, size - mid - 1, cmpFunc);
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
