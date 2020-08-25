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

#endif
