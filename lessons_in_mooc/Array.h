#ifndef _OBJ_H_
#define _OBJ_H_
#include <stdbool.h>
#define E Array_E
typedef struct E *E;
typedef struct Array Array;
struct Array {
	int size;
	E *data;
	int capacity;
};

Array* create_array(int capacity);

void release_array(Array* array);

//获取数组中的元素个数
int array_getSize(Array* array);

//获取数组的容量
int array_getCapacity(Array* array);

bool array_isEmpty(Array* array);

//在数组末尾添加元素
void addLast(Array* array, E e);

//在第index个位置插入一个新元素e
void add(Array* array, E index, E e);

void addFirst(Array* array, E e);

void array_toString(Array* array);

//获取index索引位置的元素
int get(Array* array,int index);

E getLast(Array* array);

E getFirst(Array* array);

//修改index索引位置的元素为e
void set(Array* array, int index, E e);

//查找数组中是否有元素e
bool contains(Array* array, E e);

//查找数组中元素。找到，返回索引；找不到，返回-1
int find_element_return_index(Array* array, E e);

//从数组中删除index位置的元素，返回删除的元素
int remove_in_array(Array* array, int index);

int removeFirst(Array* array);

int removeLast(Array* array);

//从数组中删除一个元素e
void removeElement(Array* array, E e);

void resize(Array* array, E newCapacity);

void array_swap(Array* array, int i, int j);
#endif