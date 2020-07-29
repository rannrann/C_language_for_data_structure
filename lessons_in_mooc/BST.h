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



//看二分搜索树中是否包含元素e
bool BST_contains(BST *bst, int e);


//二分搜索树的前序遍历
void BST_preOrder(BST *bst);


//二分搜索树的非递归前序遍历
void BST_preOrderNR(BST *bst);



//二分搜索树的中序遍历
void BST_inOrder(BST *bst);


//二分搜索树的非递归中序遍历
void BST_inOrderNR(BST *bst);


//二分搜索树的后序遍历
void BST_postOrder(BST *bst);

//二分搜索树的非递归后序遍历
void BST_postOrderNR(BST *bst);


//二分搜索树的层序遍历
void BST_levelOrder(BST *bst);



//寻找二分搜索树的最小元素
int BST_minimum(BST *bst);


//寻找二分搜索树的最大元素
int BST_maximum(BST *bst);


//从二分搜索树中删除最小值所在节点，返回最小值
int BST_removeMin(BST *bst);



//从二分搜索树中删除最大值所在节点，返回最大值
int BST_removeMax(BST *bst);

//以非递归的方式删除最小值，返回最小值
int BST_removeMinNR(BST *bst);

//以非递归的方式删除最大值，返回最大值
int BST_removeMaxNR(BST *bst);



//从二分搜索树中删除元素为e的节点
void BST_remove(BST *bst, int e);


void release_lrnode(lrNode *node);

void release_BST(BST *bst);



void lrNode_toString(lrNode *node, int depth);

void BST_toString(BST *bst);

#endif
