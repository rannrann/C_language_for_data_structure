#ifndef _OBJ_H_
#define _OBJ_H_
#include <stdbool.h>

typedef struct Array Array;

Array* create_array(int capacity);

void release_array(Array* array);

//获取数组中的元素个数
int getSize(Array* array);

//获取数组的容量
int getCapacity(Array* array);

bool isEmpty(Array* array);

//在数组末尾添加元素
void addLast(Array* array, int e);

//在第index个位置插入一个新元素e
void add(Array* array, int index, int e);

void addFirst(Array* array, int e);

void toString(Array* array);

//获取index索引位置的元素
int get(Array* array,int index);

//修改index索引位置的元素为e
void set(Array* array, int index, int e);

//查找数组中是否有元素e
bool contains(Array* array, int e);

//查找数组中元素。找到，返回索引；找不到，返回-1
int find_element_return_index(Array* array, int e);

//从数组中删除index位置的元素，返回删除的元素
int remove_in_array(Array* array, int index);

int removeFirst(Array* array);

int removeLast(Array* array);

//从数组中删除一个元素e
void removeElement(Array* array, int e);

void resize(Array* array, int newCapacity);
#endif