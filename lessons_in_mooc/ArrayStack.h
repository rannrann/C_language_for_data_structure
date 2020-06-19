#ifndef ARRAY_STACK
#define ARRAY_STACK
#include "Array.h"
#include "Stack.h"

typedef struct ArrayStack ArrayStack;

ArrayStack* creat_array_stack(int capacity);
int arrayStack_getSize(ArrayStack* as);
bool arrayStack_isEmpty(ArrayStack* as);
int arrayStack_getCapacity(ArrayStack* as);
void push(ArrayStack* as,T e);
T pop(ArrayStack* as);
T peek(ArrayStack* as);
void arrayStack_toString(ArrayStack* as);
void release_array_stack(ArrayStack* as);
#endif