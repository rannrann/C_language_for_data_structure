#ifndef _STACK_A_
#define _STACK_A_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct {
	int* array;
	int position;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack *obj = NULL;
	obj = malloc(sizeof(MinStack));
	if (obj) {
		obj->position = 7;
		obj->array = (int*)malloc(8 * sizeof(int));
	}
	return obj;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->position >= 0)
	{
		obj->array[obj->position] = x;
		obj->position--;
	}

}

void minStackPop(MinStack* obj) {
	obj->array[obj->position] = obj->array[obj->position - 1];
	obj->array[obj->position - 1] = NULL;
	obj->position--;
}

int minStackTop(MinStack* obj) {
	return obj->array[obj->position - 1];
}

int minStackGetMin(MinStack* obj) {
	int i, min;
	for (i = obj->position - 1, min = obj->array[obj->position - 1]; i < 8; i++) {
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
