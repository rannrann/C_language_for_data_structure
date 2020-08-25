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

//��ȡ�����е�Ԫ�ظ���
int array_getSize(Array* array);

//��ȡ���������
int array_getCapacity(Array* array);

bool array_isEmpty(Array* array);

//������ĩβ���Ԫ��
void addLast(Array* array, E e);

//�ڵ�index��λ�ò���һ����Ԫ��e
void add(Array* array, E index, E e);

void addFirst(Array* array, E e);

void array_toString(Array* array);

//��ȡindex����λ�õ�Ԫ��
int get(Array* array,int index);

E getLast(Array* array);

E getFirst(Array* array);

//�޸�index����λ�õ�Ԫ��Ϊe
void set(Array* array, int index, E e);

//�����������Ƿ���Ԫ��e
bool contains(Array* array, E e);

//����������Ԫ�ء��ҵ��������������Ҳ���������-1
int find_element_return_index(Array* array, E e);

//��������ɾ��indexλ�õ�Ԫ�أ�����ɾ����Ԫ��
int remove_in_array(Array* array, int index);

int removeFirst(Array* array);

int removeLast(Array* array);

//��������ɾ��һ��Ԫ��e
void removeElement(Array* array, E e);

void resize(Array* array, E newCapacity);

void array_swap(Array* array, int i, int j);
#endif