#include "ArrayStack.h"
#include "Array.h"
#include <stdio.h>
struct ArrayStack {
	Array *array;
};
ArrayStack* creat_array_stack(int capacity) {
	ArrayStack *as;
	as->array = create_array(capacity);
}
int getSize(ArrayStack* as) {
	return getSize(as->array);
}
bool isEmpty(ArrayStack* as)
{
	return isEmpty(as->array);
}
int getCapacity(ArrayStack* as)
{
	return getCapacity(as->array);
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