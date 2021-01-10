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

UnionFind4* create_unionfind4(int size) {
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

int UnionFind4_getSize(UnionFind4* uf)
{
	return uf->size;
}


//���ҹ��̣�����Ԫ��p����Ӧ�ļ��ϱ��
//O(h)���Ӷȣ�hΪ���ĸ߶�
int UnionFind4_find(UnionFind4* uf, int p) {
	if (p < 0 && p >= uf->size) {
		printf("p is out of bound.");
		exit(EXIT_FAILURE);
	}

	while (p != uf->parent[p])
		p = uf->parent[p];
	return p;
}

//����Ԫ��p��Ԫ��q�Ƿ�����һ������
//O(h)���Ӷȣ�hΪ���߶�
bool UnionFind4_isConnected(UnionFind4* uf, int p, int q) {
	return find(uf, p) == find(uf, q);
}

void UnionFind4_unionElements(UnionFind4* uf, int p, int q) {
	int pParent = UnionFind3_find(uf, p);
	int qParent = UnionFind3_find(uf, q);
	if (pParent == qParent)
		return;
	
	if (uf->rank[pParent] < uf->rank[qParent])
		uf->parent[pParent] = qParent;
	else if(uf->rank[pParent] > uf->rank[qParent])
		uf->parent[qParent] = pParent;
	else
	{
		uf->parent[qParent] = pParent;
		uf->rank[pParent] += 1;
	}
}

void release_unionfind4(UnionFind4* uf) {
	free(uf->parent);
	free(uf->rank);
	free(uf);
}
#endif
