#ifndef _UNIONFINDONE_
#define _UNIONFINDONE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct UnionFind1 UnionFind1;
struct UnionFind1 {
	int* id;
	int size;
};

UnionFind1* create_unionfind1(int size) {
	UnionFind1 *uf = NULL;
	uf = malloc(sizeof(UnionFind1));
	uf->id = malloc(sizeof(int));
	for (int i = 0; i < size; i++)
		uf->id[i] = i;
	uf->size = size;
	return uf;
}

int UnionFind1_getSize(UnionFind1 *uf) {
	return uf->size;
}

int find(UnionFind1 *uf, int p) {
	if (p < 0 && p >= uf->size) {
		printf("p is out of bound.");
		exit(EXIT_FAILURE);
	}
	return uf->id[p];
}

bool isConnected(UnionFind1 *uf,int p, int q) {
	return find(uf,p) == find(uf,q);
}


void unionElements(UnionFind1 *uf,int p, int q) {
	int pID = find(uf, p);
	int qID = find(uf, q);
	if (pID == qID)
		return;
	for (int i = 0; i < uf->size; i++)
		if (id[i] == pID)
			id[i] = qID;
}

void release_unionfind1(UnionFind1 *uf) {
	free(uf->id);
	free(uf);
}
#endif