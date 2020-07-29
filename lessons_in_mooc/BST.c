#include "BST.h"
struct lrNode {
	int e;
	lrNode *left;
	lrNode *right;
};

struct BST {
	lrNode *root;
	int size;
};



void empty_BST() {
	printf("BST is empty.\n");
}

lrNode* create_lrNode(int e) {
	lrNode *node = NULL;
	node = (lrNode*)malloc(sizeof(lrNode));
	node->e = e;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BST* create_BST() {
	BST *bst = NULL;
	bst = (BST*)malloc(sizeof(BST));
	bst->root = NULL;
	bst->size = 0;
	return bst;
}

int BST_getSzie(BST *bst) {
	return bst->size;
}

//向以node为根的二分搜索树中插入元素e,递归算法
//返回插入新节点后二分搜索树的根
lrNode* lrnode_add(BST *bst, lrNode *node, int e) {
	if (node == NULL) {
		bst->size++;
		return create_lrNode(e);
	}
	if (e < node->e)
		node->left = lrnode_add(bst, node->left, e);
	else if (e > node->e)
		node->right = lrnode_add(bst, node->right, e);
	return node;
}

void BST_add(BST *bst, int e) {
	bst->root = lrnode_add(bst, bst->root, e);
}



//看以node为根的二分搜索树中是否包含元素e
bool lrNode_contains(lrNode *node, int e) {
	if (node == NULL)
		return false;
	if (e == node->e)
		return true;
	else if (e < node->e)
		return lrNode_contains(node->left, e);
	else
		return lrNode_contains(node->right, e);
}

//看二分搜索树中是否包含元素e
bool BST_contains(BST *bst, int e) {
	return lrNode_contains(bst->root, e);
}

//前序遍历以node为根的二分搜索树，递归算法
void lrNode_preOrder(lrNode *node) {
	if (node != NULL) {
		printf("%d ", node->e);
		lrNode_preOrder(node->left);
		lrNode_preOrder(node->right);
	}

}



//二分搜索树的前序遍历
void BST_preOrder(BST *bst) {
	lrNode_preOrder(bst->root);
	printf("\n");
}


//二分搜索树的非递归前序遍历
void BST_preOrderNR(BST *bst) {
	ArrayStack *as = create_array_stack(10);
	push(as, bst->root);
	while (!arrayStack_isEmpty(as)) {
		lrNode *node = pop(as);
		printf("%d ", node->e);

		if (node->right != NULL)
			push(as, node->right);
		if (node->left != NULL)
			push(as, node->left);
	}
	release_array_stack(as);
	printf("\n");
}


void lrNode_inOrder(lrNode *node) {
	if (node == NULL)
		return;
	lrNode_inOrder(node->left);
	printf("%d ", node->e);
	lrNode_inOrder(node->right);
}

//二分搜索树的中序遍历
void BST_inOrder(BST *bst) {
	lrNode_inOrder(bst->root);
	printf("\n");
}


//二分搜索树的非递归中序遍历
void BST_inOrderNR(BST *bst) {
	ArrayStack *as = create_array_stack(10);
	lrNode *node = bst->root;
	while (!arrayStack_isEmpty(as) || node != NULL) {
		while (node != NULL) {
			push(as, node);
			node = node->left;
		}
		lrNode *sNode = pop(as);
		printf("%d ", sNode->e);
		node = sNode->right;
	}
	printf("\n");
	release_array_stack(as);
}


void lrNode_postOrder(lrNode *node) {
	if (node == NULL)
		return;
	lrNode_postOrder(node->left);
	lrNode_postOrder(node->right);
	printf("%d ", node->e);
}

//二分搜索树的后序遍历
void BST_postOrder(BST *bst) {
	lrNode_postOrder(bst->root);
	printf("\n");
}

//二分搜索树的非递归后序遍历
void BST_postOrderNR(BST *bst) {
	ArrayStack *as = create_array_stack(10);
	lrNode *node = bst->root;
	lrNode *pre = NULL;
	while (!arrayStack_isEmpty(as) || node != NULL) {
		while (node != NULL) {
			push(as, node);
			node = node->left;
		}
		lrNode *sNode = peek(as);
		if (sNode->right == NULL || pre == sNode->right) {
			pop(as);
			pre = sNode;
			printf("%d ", sNode->e);
			//node = peek(as);有这一句会让父母节点再次进入输入环节
		}
		else {
			node = sNode->right;
		}
	}
	printf("\n");
	release_array_stack(as);
}


//二分搜索树的层序遍历
void BST_levelOrder(BST *bst) {
	ArrayQueue *aq = create_array_queue(10);
	arrayQueue_enqueue(aq, bst->root);
	while (!arrayQueue_isEmpty(aq)) {
		lrNode *cur = arrayQueue_dequeue(aq);
		printf("%d ", cur->e);

		if (cur->left != NULL)
			arrayQueue_enqueue(aq, cur->left);
		if (cur->right != NULL)
			arrayQueue_enqueue(aq, cur->right);
	}
	release_array_queue(aq);
	printf("\n");
}


//返回以node为根的二分搜索树的最小值所在的节点
lrNode* lrNode_minimum(lrNode *node) {
	if (node->left == NULL)
		return node;
	return lrNode_minimum(node->left);
}



//寻找二分搜索树的最小元素
int BST_minimum(BST *bst) {
	if (bst->size == 0) {
		atexit(empty_BST);
		exit(EXIT_FAILURE);
	}
	return lrNode_minimum(bst->root)->e;
}

//返回以node为根的二分搜索树的最大值所在的节点
lrNode* lrNode_maximum(lrNode *node) {
	if (node->right == NULL)
		return node;
	return lrNode_maximum(node->right);
}



//寻找二分搜索树的最大元素
int BST_maximum(BST *bst) {
	if (bst->size == 0) {
		atexit(empty_BST);
		exit(EXIT_FAILURE);
	}
	return lrNode_maximum(bst->root)->e;
}


//删除掉以node为根的二分搜索树中的最小节点
//返回删除节点后新的二分搜索树的根
lrNode* lrNode_removeMin(BST *bst, lrNode *node) {
	if (node->left == NULL) {
		lrNode *rightNode = node->right;
		node->right = NULL;
		bst->size--;
		free(node);
		node = NULL;
		return rightNode;
	}

	node->left = lrNode_removeMin(bst, node->left);
	return node;
}

//从二分搜索树中删除最小值所在节点，返回最小值
int BST_removeMin(BST *bst) {
	int ret = BST_minimum(bst);
	bst->root = lrNode_removeMin(bst, bst->root);
	return ret;
}


//删除掉以node为根的二分搜索树中的最大节点
//返回删除节点后新的二分搜索树的根
lrNode* lrNode_removeMax(BST *bst, lrNode *node) {
	if (node->right == NULL) {
		lrNode *rightNode = node->left;
		node->left = NULL;
		bst->size--;
		free(node);
		node = NULL;
		return rightNode;
	}

	node->right = lrNode_removeMax(bst, node->right);
	return node;
}

//从二分搜索树中删除最大值所在节点，返回最大值
int BST_removeMax(BST *bst) {
	int ret = BST_maximum(bst);
	bst->root = lrNode_removeMax(bst, bst->root);
	return ret;
}

//以非递归的方式删除最小值，返回最小值
int BST_removeMinNR(BST *bst) {
	lrNode *node = bst->root;
	if (node->left == NULL) {
		int ret = node->e;
		lrNode *ancestor = node;
		node = node->right;
		free(ancestor);
		ancestor = NULL;
		return ret;
	}
	else
	{
		lrNode *parent = node;
		while (node->left != NULL)
			node = node->left;
		while (parent->left != node)
			parent = parent->left;

		int ret = node->e;
		parent->left = node->right;
		node->right = NULL;
		free(node);
		node = NULL;
		bst->size--;
		return ret;
	}
}

//以非递归的方式删除最大值，返回最大值
int BST_removeMaxNR(BST *bst) {
	lrNode *node = bst->root;
	if (node->right == NULL) {
		int ret = node->e;
		lrNode *ancestor = node;
		node = node->left;
		free(ancestor);
		ancestor = NULL;
		return ret;
	}
	else
	{
		lrNode *parent = node;
		while (node->right != NULL)
			node = node->right;
		while (parent->right != node)
			parent = parent->right;

		int ret = node->e;
		parent->right = node->left;
		node->left = NULL;
		free(node);
		node = NULL;
		bst->size--;
		return ret;
	}
}



//删除以node为根的二分搜索树中值为e的节点，递归算法
//返回删除节点后新的二分搜索树的根
lrNode* lrNode_remove(BST *bst, lrNode *node, int e) {
	if (node->e == e) {
		if (node->left == NULL) {
			return lrNode_removeMin(bst, node);
		}
		if (node->right == NULL) {
			return lrNode_removeMin(bst, node);
		}
		lrNode *successor = lrNode_minimum(node->right);
		successor->right = lrNode_removeMin(bst, node->right);
		successor->left = node->left;
		node->left = NULL;
		node->right = NULL;
		free(node);
		node = NULL;
		return successor;
	}
	else if (node->e > e) {
		return lrNode_remove(bst, node->left, e);
	}
	else if (node->e < e) {
		return lrNode_remove(bst, node->right, e);
	}
	else {
		return NULL;
	}
}


//从二分搜索树中删除元素为e的节点
void BST_remove(BST *bst, int e) {
	bst->root = lrNode_remove(bst, bst->root, e);
}


void release_lrnode(lrNode *node) {
	if (node == NULL)
		return;
	else {
		release_lrnode(node->left);
		release_lrnode(node->right);
		printf("%d\n", node->e);
		free(node);
		node = NULL;
	}

}

void release_BST(BST *bst) {
	//清除节点
	release_lrnode(bst->root);
	free(bst);
	bst = NULL;
}

void print_line(int depth) {
	for (int i = 0; i < depth; i++)
		printf("--");
}

void lrNode_toString(lrNode *node, int depth) {
	if (node == NULL)
	{
		print_line(depth);
		printf("null\n");

	}
	else {
		print_line(depth);
		printf("%d\n", node->e);
		lrNode_toString(node->left, depth + 1);
		lrNode_toString(node->right, depth + 1);
	}
}

void BST_toString(BST *bst) {
	lrNode_toString(bst->root, 0);
}