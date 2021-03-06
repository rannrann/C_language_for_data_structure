#ifndef _OBJ_H_D
#define _OBJ_H_D

#define T Stack_T

typedef struct T *T;

extern int arrayStack_getSize(T *t);
extern bool arrayStack_isEmpty(T *t);
extern void push(T *t, T e);
extern T pop(T *t);
extern T peek(T *t);

#endif
