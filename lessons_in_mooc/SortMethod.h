#ifndef _SORT_METHOD_
#define _SORT_METHOD_
void bubble_sort(int *arr, int size)
{
	for (int i = size-1; i > 0 ; i--) {
		for (int j = size-1; j > size - i -1; j--) {
			if (arr[j] > arr[j - 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j-1]=tmp;
			}
		}
	}
}



//quick sort
void swap_element(int *a, int *b) {
	int *tmp = a;
	a = b;
	b = tmp;
}


int partition(int *arr, int start, int end) {
	int pivot = arr[end];
	int pIndex = start;
	for (int i = start; i < end; i++) {
		if (arr[i] <= pivot) {
			swap_element(arr + i, arr + pIndex);
			pIndex++;
		}
	}
	swap_element(arr + end, arr + pIndex);
	return pIndex;
}

int randomized_partition(int *arr, int start, int end)
{
	int pivot_index = rand() % (end-start+1) + start;
	swap_element(arr + pivot_index, arr + end);
	return partition(arr, start, end);
}

void quick_sort(int *arr, int start, int end) {
	if (start < end) {
		int pIndex = randomized_partition(arr, start, end);
		quick_sort(arr, start, pIndex - 1);
		quick_sort(arr, pIndex + 1, end);
	}
}

#endif
