#ifndef _BSTSET_
#define _BSTSET_
#include "BST.h"
typedef struct BSTSet BSTSet;
struct BSTSet {
	BST *bst;
};

BSTSet* create_BSTSet() {
	BSTSet *bstset = NULL;
	bstset = (BSTSet*)malloc(sizeof(BSTSet));
	bstset->bst = create_BST();
	return bstset;
}

int BSTSet_getSize(BSTSet *bstset) {
	return BST_getSzie(bstset->bst);
}

bool BSTSet_isEmpty(BSTSet *bstset) {
	return BSTSet_getSize(bstset) == 0 ? true: false;
}

void BSTSet_add(BSTSet *bstset, int e) {
	BST_add(bstset->bst, e);
}

bool BSTSet_contains(BSTSet *bstset, int e) {
	return BST_contains(bstset->bst, e);
}

void BSTSet_remove(BSTSet *bstset, int e) {
	BST_remove(bstset->bst, e);
}

void release_BSTSet(BSTSet *bstset) {
	release_BST(bstset->bst);
	free(bstset);
	bstset = NULL;
}
#endif
