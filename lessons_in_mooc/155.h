#ifndef _STACK_A_
#define _STACK_A_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct {
	int* array;
	int position;
	int capacity;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack *obj = NULL;
	obj = malloc(sizeof(MinStack));
	if (obj) {
		obj->position = 0;
		obj->capacity = 1;
		obj->array = (int*)malloc(sizeof(int));
		memset(obj->array, NULL, obj->capacity * sizeof(int));
	}
	return obj;
}


void StringStack(MinStack* obj) {
	//printf("MinStack: position = %d, capacity = %d\n", obj->position, obj->capacity);
	printf("[");
	int i;
	for (i = 0; i < obj->capacity; i++) {
		printf("%d", obj->array[i]);
		if (i != obj->capacity - 1)
			printf(",");
	}
	printf("]\n");

}

void minStackPush(MinStack* obj, int x) {
	if (obj->position < obj->capacity) {
		obj->array[obj->position] = x;
		obj->position++;
	}
	else
	{
		//add one capacity
		obj->capacity++;
		int *arr = (int *)malloc(obj->capacity * sizeof(int));
		int i;
		for (i = 0; i < obj->capacity - 1; i++)
			arr[i] = obj->array[i];
		free(obj->array);
		obj->array = NULL;
		obj->array = arr;
		arr = NULL;

		obj->array[obj->position] = x;
		obj->position++;
	}
}

void minStackPop(MinStack* obj) {
	obj->capacity--;
	obj->position--;
	int *arr = (int *)malloc(obj->capacity * sizeof(int));
	int i;
	for (i = 0; i < obj->capacity; i++)
		arr[i] = obj->array[i];
	obj->array = NULL;
	obj->array = arr;
	arr = NULL;

}

int minStackTop(MinStack* obj) {
	return obj->array[obj->position - 1];
}

int minStackGetMin(MinStack* obj) {
	int i, min;
	for (i = 0, min = obj->array[0]; i < obj->capacity; i++) {
		if (obj->array[i] < min)
			min = obj->array[i];
	}
	return min;

}



void minStackFree(MinStack* obj) {
	if (!obj) return;
	if (obj->array) {
		free(obj->array);
		obj->array = NULL;
	}
	free(obj);
	obj = NULL;
}


#endif