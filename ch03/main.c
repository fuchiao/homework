#include <stdio.h>
#include "sort.h"
int main()
{
	int data[] = {10, 2, 5, 34, 12, 39, 7, 3, 24, 19};
	void * ary[10];
	int i;

	printf("random order: ");
	for (i = 0; i < 10; i++) {
		ary[i] = &data[i];
		printf("%d ", *(int *)ary[i]);
	}
	printf("\n");

	merge_sort(ary, sizeof(data) / sizeof(*data), cmp_reverse);

	printf("after sorting: ");
	for (i = 0; i < 10; i++)
		printf("%d ", *(int *)ary[i]);
	printf("\n");

	return 0;
}
