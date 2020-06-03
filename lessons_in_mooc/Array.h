#ifndef _OBJ_H_
#define _OBJ_H_
#include <stdbool.h>

typedef struct Array Array;

Array* create_array(int capacity);

void release_array(Array* array);

//��ȡ�����е�Ԫ�ظ���
int getSize(Array* array);

//��ȡ���������
int getCapacity(Array* array);

bool isEmpty(Array* array);

//������ĩβ���Ԫ��
void addLast(Array* array, int e);

//�ڵ�index��λ�ò���һ����Ԫ��e
void add(Array* array, int index, int e);

void addFirst(Array* array, int e);

void toString(Array* array);

//��ȡindex����λ�õ�Ԫ��
int get(Array* array,int index);

//�޸�index����λ�õ�Ԫ��Ϊe
void set(Array* array, int index, int e);

//�����������Ƿ���Ԫ��e
bool contains(Array* array, int e);

//����������Ԫ�ء��ҵ��������������Ҳ���������-1
int find_element_return_index(Array* array, int e);

//��������ɾ��indexλ�õ�Ԫ�أ�����ɾ����Ԫ��
int remove_in_array(Array* array, int index);

int removeFirst(Array* array);

int removeLast(Array* array);

//��������ɾ��һ��Ԫ��e
void removeElement(Array* array, int e);

void resize(Array* array, int newCapacity);
#endif