#include "ArrayStack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct ArrayStack {
	Array *array;
};

ArrayStack* create_array_stack(int capacity) {
	ArrayStack *as = NULL;
	as = malloc(sizeof(ArrayStack));
	as->array = create_array(capacity);
	return as;
}
int arrayStack_getSize(ArrayStack* as) {
	return array_getSize(as->array);
}
bool arrayStack_isEmpty(ArrayStack* as)
{
	return array_isEmpty(as->array);
}
int arrayStack_getCapacity(ArrayStack* as)
{
	return array_getCapacity(as->array);
}
void push(ArrayStack* as, T t)
{
	addLast(as->array, t);
}

T pop(ArrayStack* as) {
	return removeLast(as->array);
}
T peek(ArrayStack* as) {
	return getLast(as->array);
}
void arrayStack_toString(ArrayStack* as) {
	printf("Stack:[");
	int i;
	for (i = 0; i < array_getSize(as->array); i++) {
		printf("%d", as->array->data[i]);
		if (i != array_getSize(as->array) - 1)
			printf(",");
	}
	printf("] top\n");
}

void release_array_stack(ArrayStack* as) {
	release_array(as->array);
	free(as);
	as = NULL;
}