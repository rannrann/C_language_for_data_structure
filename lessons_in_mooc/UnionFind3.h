#ifndef _UNIONFINDTHREE_
#define _UNIONFINDTHREE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct UnionFind3 UnionFind3;
struct UnionFind3 {
	int *parent;
	int *sz;
	int size;
};

UnionFind3* create_unionfind2(int size) {
	UnionFind3 *uf = NULL;
	uf = malloc(sizeof(UnionFind3));
	uf->size = size;
	uf->parent = malloc(sizeof(int)*size);
	uf->sz = malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		uf->parent[i] = i;
		uf->sz[i] = 1;
	}
	return uf;
}

int UnionFind3_getSize(UnionFind3* uf)
{
	return uf->size;
}


//查找过程，查找元素p所对应的集合编号
//O(h)复杂度，h为树的高度
int UnionFind3_find(UnionFind3* uf, int p) {
	if (p < 0 && p >= uf->size) {
		printf("p is out of bound.");
		exit(EXIT_FAILURE);
	}

	while (p != uf->parent[p])
		p = uf->parent[p];
	return p;
}

//查找元素p和元素q是否所属一个集合
//O(h)复杂度，h为树高度
bool UnionFind3_isConnected(UnionFind3* uf, int p, int q) {
	return find(uf, p) == find(uf, q);
}

void UnionFind3_unionElements(UnionFind3* uf, int p, int q) {
	int pParent = UnionFind3_find(uf, p);
	int qParent = UnionFind3_find(uf, q);
	if (pParent == qParent)
		return;
	if (uf->sz[pParent] < uf->sz[qParent])
	{
		uf->parent[pParent] = qParent;
		uf->sz[qParent] += uf->sz[pParent];
	}
	else {
		uf->parent[qParent] = pParent;
		uf->sz[pParent] += uf->sz[qParent];
	}
		
}

void release_unionfind3(UnionFind3* uf) {
	free(uf->parent);
	free(uf);
}
#endif
