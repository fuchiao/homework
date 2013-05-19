#include <stdio.h>

int cmp(void * a, void * b) {
	return *(int *)a - *(int *)b;
}
int cmp_reverse(void *, void *) {
	return *(int *)b - *(int *)a;
}
static void swap(void ** a, void ** b) {
	void * tmp = *a;
	*a = *b;
	*b = tmp;
}
void merge_sort(void ** ary, int size, DataCmpFunc cmpFunc) {

}
void quick_sort(void ** ary, int size, DataCmpFunc cmpFunc) {

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
