typedef int (*DataCmpFunc)(void *, void *);
int cmp(void *, void *);
int cmp_reverse(void *, void *);
void swap(void ** a, void ** b);
void merge_sort(void **, int, DataCmpFunc);
void quick_sort(void **, int, DataCmpFunc);
void bubble_sort(void **, int , DataCmpFunc);

