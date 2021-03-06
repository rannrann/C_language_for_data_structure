#include "Array.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Array {
	int size;
	E *data;
	int capacity;
};
void index_exception() {
	printf("Add failed. Require index >=0 and index <= size.\n");
}

void get_exception() {
	printf("Get failed. Index is illegal.\n");
}


void set_exception() {
	printf("Set failed. Index is illegal.\n");
}

void remove_exception() {
	printf("Remove failed. Index is illegal.\n");
}

Array* create_array(int capacity) {
	Array *array = NULL;
	array = malloc(sizeof(Array));
	if (array) {
		array->size = 0;
		array->data = (E*)malloc(capacity * sizeof(E));
		array->capacity = capacity;
	}
	return array;
}

E* retData(Array *array) {
	return array->data;
}

Array* create_array_with_array(E* arr,int length) {
	Array *array = NULL;
	array = malloc(sizeof(Array));
	array->data = (E*)malloc(length * sizeof(E));
	array->capacity = length;
	array->size = length;
	for (int i = 0; i < length; i++) 
		array->data[i] = arr[i];
	return array;
}

void release_array(Array* array) {
	if (!array) return;
	if (array->data) {
		free(array->data);
		array->data = NULL;
	}
	free(array);
	array = NULL;
}

//获取数组中的元素个数
int array_getSize(Array* array) {
	return array->size;
}

//获取数组的容量
int array_getCapacity(Array* array) {
	return array->capacity;
}
bool array_isEmpty(Array* array){
	return array->size == 0 ? true : false;
}

void addLast(Array* array,E e) {
	add(array,array->size,e);
}

void addFirst(Array* array, E e) {
	add(array, 0, e);
}

void add(Array* array, int index, E e) {

	if (index<0 || index>array->size) {
		atexit(index_exception);
		exit(EXIT_FAILURE);
	}
	if (array->size == array->capacity)
		resize(array, 2 * (array->capacity));
	for (int i = array->size - 1; i >= index; i--)
		array->data [i + 1] = array->data [i];
	array->data[index] = e;//a[1]的意义等于*(a+1)
	array->size++;
}


void array_toString_with_newline(Array* array) {
	printf("Array: size = %d, capacity = %d\n", array->size, array->capacity);
	for (int i = 0; i < array->size; i++)
		printf("%d\n", array->data[i]);
}

void array_toString(Array* array) {
	printf("Array: size = %d, capacity = %d\n",array->size,array->capacity);
	printf("[");
	int i;
	for (i = 0; i < array->size; i++) {
		printf("%d", array->data[i]);
		if (i != array->size - 1)
			printf(",");
	}
	printf("]\n");
}

//获取index索引位置的元素
int get(Array* array, int index) {
	if (index < 0 || index >= array->size) {
		atexit(get_exception);
		exit(EXIT_FAILURE);
	}
	return array->data[index];
}

E getLast(Array* array) {
	return get(array, array->size - 1);
}

E getFirst(Array* array) {
	return get(array, 0);
}

//修改index索引位置的元素为e
void set(Array* array, int index, E e) {
	if (index < 0 || index >= array->size) {
		atexit(set_exception);
		exit(EXIT_FAILURE);
	}
	array->data[index] = e;
}

//查找数组中是否有元素e
bool contains(Array* array, E e) {
	for (int i = 0; i < array->size; i++) {
		if (array->data[i] == e)
			return true;
	}
	return false;
}

//查找数组中元素。找到，返回索引；找不到，返回-1
int find_element_return_index(Array* array, E e) {
	for (int i = 0; i < array->size; i++) {
		if (array->data[i] == e)
			return i;
	}
	return -1;
}

//从数组中删除index位置的元素，返回删除的元素
int remove_in_array(Array* array, int index) {
	if (index < 0 || index >= array->size) {
		atexit(remove_exception);
		exit(EXIT_FAILURE);
	}
	int ret = array->data[index];
	for (int i = index + 1; i < array->size; i++)
		array->data[i - 1] = array->data[i];
	array->size--;

	if (array->size == array->capacity / 4 && array->capacity / 2 != 0)
		resize(array,array->capacity / 2);//注意：有可能array->capacity/2=0，不可能将长度变为0.(比如capacity为1，size为0。那么size= 1/4 =0, 进而resize(1/2=0))

	return ret;
}

int removeFirst(Array* array)
{
	return remove_in_array(array, 0);
}

int removeLast(Array* array) {
	return remove_in_array(array, array->size - 1);
}


//从数组中删除一个元素e
void removeElement(Array* array, E e)
{
	int index = find_element_return_index(array, e);
	if (index != -1)
		remove_in_array(array, index);
}

void resize(Array* array, int newCapacity) {
	int* newData = (int*)malloc(newCapacity * sizeof(int));
	for (int i = 0; i < array->size; i++)
		newData[i] = array->data[i];
	free(array->data);
	array->data = NULL;
	array->data = newData;
	newData = NULL;//我认为可以不free(newData)的原因是，空间已经被array->data指向了，所以只需要让他指向NULL即可
	array->capacity = newCapacity;
}

void array_swap(Array* array, int i, int j) {
	if (i < 0 || i >= array->size || j < 0 || j >= array->size)
	{
		atexit(index_exception);
		exit(EXIT_FAILURE);
	}
	E change = array->data[i];
	array->data[i] = array->data[j];
	array->data[j] = change;
}