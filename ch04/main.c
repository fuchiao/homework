#include "double_linked_list.h"
#include <stdio.h>
int main() {
	int sum = 0, max = 0;
	int input[] = {32, 10, 66, 25, 17};
	int i;
	Node * headPtr = NULL;
	#if 0
	insert(&headPtr, "John Titor");
	insert(&headPtr, "Bill Gates");
	insert(&headPtr, "Steve Jobs");
	insert(&headPtr, "Morris Chang");
	insert(&headPtr, "Gilbert Areanas");
	list(headPtr, print_string);
	#endif
	for (i = 0; i < 5; i++) {
		insert(&headPtr, (void *)input[i]);
	}
	list(headPtr, print_int);
	foreach(headPtr, find_max, &sum);
	foreach(headPtr, summarize, &max);
	printf("MAX: %d, SUM: %d\n", max, sum);

	return 0;
}
