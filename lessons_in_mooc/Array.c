#include "Array.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Array {
	int size;
	int *data;
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
		array->data = (int*)malloc(capacity * sizeof(int));
		array->capacity = capacity;
	}
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

//��ȡ�����е�Ԫ�ظ���
int getSize(Array* array) {
	return array->size;
}

//��ȡ���������
int getCapacity(Array* array) {
	return array->capacity;
}
bool isEmpty(Array* array){
	return array->size == 0 ? true : false;
}

void addLast(Array* array,int e) {
	add(array,array->size,e);
}

void addFirst(Array* array, int e) {
	add(array, 0, e);
}

void add(Array* array, int index, int e) {

	if (index<0 || index>array->size) {
		atexit(index_exception);
		exit(EXIT_FAILURE);
	}
	if (array->size == array->capacity)
		resize(array, 2 * (array->capacity));
	for (int i = array->size - 1; i >= index; i--)
		array->data [i + 1] = array->data [i];
	array->data[index] = e;//a[1]���������*(a+1)
	array->size++;
}



void toString(Array* array) {
	printf("Array: size = %d, capacity = %d\n",array->size,array->capacity);
	printf("[");
	int i;
	for (i = 0; i < array->size; i++) {
		printf("%d",*(array->data + i));
		if (i != array->size - 1)
			printf(",");
	}
	printf("]\n");
}

//��ȡindex����λ�õ�Ԫ��
int get(Array* array, int index) {
	if (index < 0 || index >= array->size) {
		atexit(get_exception);
		exit(EXIT_FAILURE);
	}
	return array->data[index];
}

//�޸�index����λ�õ�Ԫ��Ϊe
void set(Array* array, int index, int e) {
	if (index < 0 || index >= array->size) {
		atexit(set_exception);
		exit(EXIT_FAILURE);
	}
	array->data[index] = e;
}

//�����������Ƿ���Ԫ��e
bool contains(Array* array, int e) {
	for (int i = 0; i < array->size; i++) {
		if (array->data[i] == e)
			return true;
	}
	return false;
}

//����������Ԫ�ء��ҵ��������������Ҳ���������-1
int find_element_return_index(Array* array, int e) {
	for (int i = 0; i < array->size; i++) {
		if (array->data[i] == e)
			return i;
	}
	return -1;
}

//��������ɾ��indexλ�õ�Ԫ�أ�����ɾ����Ԫ��
int remove_in_array(Array* array, int index) {
	if (index < 0 || index >= array->size) {
		atexit(remove_exception);
		exit(EXIT_FAILURE);
	}
	int ret = array->data[index];
	for (int i = index + 1; i < array->size; i++)
		array->data[i - 1] = array->data[i];
	array->size--;

	if (array->size == array->capacity / 2)
		resize(array,array->capacity / 2);

	return ret;
}

int removeFirst(Array* array)
{
	return remove_in_array(array, 0);
}

int removeLast(Array* array) {
	return remove_in_array(array, array->size - 1);
}


//��������ɾ��һ��Ԫ��e
void removeElement(Array* array, int e)
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
	newData = NULL;
	array->capacity = newCapacity;
}