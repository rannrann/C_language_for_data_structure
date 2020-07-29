#ifndef _BST_
#define _BST_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"
#include "ArrayQueue.h"
typedef struct lrNode lrNode;
typedef struct BST BST;


void empty_BST();

lrNode* create_lrNode(int e);

BST* create_BST();

int BST_getSzie(BST *bst);

void BST_add(BST *bst, int e);



//���������������Ƿ����Ԫ��e
bool BST_contains(BST *bst, int e);


//������������ǰ�����
void BST_preOrder(BST *bst);


//�����������ķǵݹ�ǰ�����
void BST_preOrderNR(BST *bst);



//�������������������
void BST_inOrder(BST *bst);


//�����������ķǵݹ��������
void BST_inOrderNR(BST *bst);


//�����������ĺ������
void BST_postOrder(BST *bst);

//�����������ķǵݹ�������
void BST_postOrderNR(BST *bst);


//�����������Ĳ������
void BST_levelOrder(BST *bst);



//Ѱ�Ҷ�������������СԪ��
int BST_minimum(BST *bst);


//Ѱ�Ҷ��������������Ԫ��
int BST_maximum(BST *bst);


//�Ӷ�����������ɾ����Сֵ���ڽڵ㣬������Сֵ
int BST_removeMin(BST *bst);



//�Ӷ�����������ɾ�����ֵ���ڽڵ㣬�������ֵ
int BST_removeMax(BST *bst);

//�Էǵݹ�ķ�ʽɾ����Сֵ��������Сֵ
int BST_removeMinNR(BST *bst);

//�Էǵݹ�ķ�ʽɾ�����ֵ���������ֵ
int BST_removeMaxNR(BST *bst);



//�Ӷ�����������ɾ��Ԫ��Ϊe�Ľڵ�
void BST_remove(BST *bst, int e);


void release_lrnode(lrNode *node);

void release_BST(BST *bst);



void lrNode_toString(lrNode *node, int depth);

void BST_toString(BST *bst);

#endif
