#ifndef _NINE_SEVEN_THREE_
#define _NINE_SEVEN_THREE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct Dist Dist;
struct Dist {
	int index;
	int distance;
};

void test_siftDown(Dist **dist, int size, int index)
{
	while (index * 2 + 1 < size) {
		int j = index * 2 + 1;
		if (j + 1 < size && dist[j + 1]->distance > dist[j]->distance)
			j++;
		if (dist[index]->distance >= dist[j]->distance)
			break;
		Dist *tmp = dist[index];
		dist[index] = dist[j];
		dist[j] = tmp;
		index = j;
	}
	printf("siftDown done\n");
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes) {
	*returnSize = K;
	Dist **dist = malloc(sizeof(Dist)*pointsSize);
	for (int i = 0; i < pointsSize; i++) {
		dist[i] = malloc(sizeof(Dist));
	}
	for (int i = 0; i < pointsSize; i++)
	{
		dist[i]->index = i;
		dist[i]->distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		printf("dist[%d]->index=%d, dist[%d]->distance=%d\n", i, dist[i]->index, i, dist[i]->distance);
	}
	Dist **maxHeap = malloc(sizeof(Dist)*K);
	printf("Dist done\n");
	for (int i = 0; i < K; i++) {
		maxHeap[i] = malloc(sizeof(Dist));
		maxHeap[i]->index = dist[i]->index;
		maxHeap[i]->distance = dist[i]->distance;
	}
	for (int i = (K <= 2) ? 1 : (K - 2) / 2; i >= 0; i--)
	{
		test_siftDown(maxHeap, K, i);
	}
	printf("maxheap done\n");
	printf("maxHeap[0]->index=%d\n", maxHeap[0]->index);
	for (int i = K; i < pointsSize; i++) {
		if (dist[i]->distance < maxHeap[0]->distance)
		{
			maxHeap[0] = dist[i];
			test_siftDown(maxHeap, K, 0);
		}
	}
	printf("maxHeap[0]->index=%d\n", maxHeap[0]->index);
	printf("replace done\n");
	//printf("pointsColSize=%d\n",pointsColSize); 16
	//printf("pointsSize=%d\n",pointsSize); 2

	*returnColumnSizes = malloc(sizeof(int)*K);
	for (int i = 0; i < K; i++)
	{
		returnColumnSizes[0][i] = 2;
	}
	printf("returnColumnSizes done\n");
	int **ret = malloc(sizeof(int)*K);
	for (int i = 0; i < K; i++) {
		ret[i] = malloc(sizeof(int) * 2);
	}
	printf("ret done\n");
	for (int i = 0; i < K; i++) {
		printf("maxHeap[%d]->index=%d\n", i, maxHeap[i]->index);
		ret[i][0] = points[maxHeap[i]->index][0];
		ret[i][1] = points[maxHeap[i]->index][1];
	}
	return ret;
}
#endif