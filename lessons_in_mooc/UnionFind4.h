#ifndef _UNIONFINDFOUR_
#define _UNIONFINDFOUR_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct UnionFind4 UnionFind4;
struct UnionFind4 {
	int *parent;
	int *rank;
	int size;
};

UnionFind4* create_unionfind2(int size) {
	UnionFind4 *uf = NULL;
	uf = malloc(sizeof(UnionFind4));
	uf->size = size;
	uf->parent = malloc(sizeof(int)*size);
	uf->rank = malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		uf->parent[i] = i;
		uf->rank[i] = 1;
	}
	return uf;
}

int UnionFind3_getSize(UnionFind4* uf)
{
	return uf->size;
}


//查找过程，查找元素p所对应的集合编号
//O(h)复杂度，h为树的高度
int UnionFind3_find(UnionFind4* uf, int p) {
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
bool UnionFind3_isConnected(UnionFind4* uf, int p, int q) {
	return find(uf, p) == find(uf, q);
}

void UnionFind3_unionElements(UnionFind4* uf, int p, int q) {
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

void release_unionfind3(UnionFind4* uf) {
	free(uf->parent);
	free(uf);
}
#endif
