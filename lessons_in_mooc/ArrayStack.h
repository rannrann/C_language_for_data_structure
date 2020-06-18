#ifndef ARRAY_STACK
#define ARRAY_STACK
#include "Array.h"
#include "Stack.h"

typedef struct ArrayStack ArrayStack;

ArrayStack* creat_array_stack(int capacity);
int getSize(ArrayStack* as);
bool isEmpty(ArrayStack* as);
int getCapacity(ArrayStack* as);
void push(ArrayStack* as,T e);
T pop(ArrayStack* as);
T peek(ArrayStack* as);
#endif