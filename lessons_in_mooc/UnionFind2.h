#ifndef _UNIONFINDTWO_
#define _UNIONFINDTWO_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct UnionFind2 UnionFind2;
struct UnionFind2 {
	int* parent;
	int size;
};

UnionFind2* create_unionfind2(int size) {
	UnionFind2 *uf = NULL;
	uf = malloc(sizeof(UnionFind2));
	uf->size = size;
	uf->parent = malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
		uf->parent[i] = i;
	return uf;
}

int UnionFind2_getSize(UnionFind2* uf)
{
	return uf->size;
}


//���ҹ��̣�����Ԫ��p����Ӧ�ļ��ϱ��
//O(h)���Ӷȣ�hΪ���ĸ߶�
int UnionFind2_find(UnionFind2* uf, int p) {
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
bool isConnected(UnionFind2* uf, int p, int q) {
	return find(uf, p) == find(uf, q);
}

void UnionFind2_unionElements(UnionFind2* uf, int p, int q) {
	int pParent = UnionFind2_find(uf, p);
	int qParent = UnionFind2_find(uf, q);
	if (pParent == qParent)
		return;
	uf->parent[pParent] = qParent;
}

void release_unionfind2(UnionFind2* uf) {
	free(uf->parent);
	free(uf);
}
#endif
