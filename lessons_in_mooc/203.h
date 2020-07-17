#ifndef _TWO_ZERO_THREE_
#define _TWO_ZERO_THREE_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode {
	int val;
	struct ListNode *next;
};


void addElements(struct ListNode* head, int e) {
	struct ListNode *prev = head;
	while (prev->next != NULL) prev = prev->next;
	prev->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	prev->next->val = e;
	prev->next->next = NULL;
}


struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode *dummyhead = malloc(sizeof(struct ListNode));
	dummyhead->val = 0;
	dummyhead->next = head;
	bool flag;
	for (struct ListNode *prev = dummyhead; prev != NULL; prev = (flag == true) ? prev : prev->next) {
		flag = false;
		if (prev->next != NULL && prev->next->val == val) {
			struct ListNode *goal = prev->next;
			if (prev == dummyhead)head = head->next;
			prev->next = goal->next;
			goal->next = NULL;
			free(goal);
			goal = NULL;
			flag = true;
		}
	}
	free(dummyhead);
	dummyhead = NULL;
	return head;

}


void listNode_toString(struct ListNode *head) {
	printf("listNode:[");
	for (struct ListNode* cur = head; cur != NULL; cur = cur->next) {
		printf("%d ", cur->val);
	}
	printf("]\n");
}
void release_listNode(struct ListNode *head) {
	struct ListNode *prev = head;
	while (true) {
		if (prev->next->next == NULL) {
			if (prev == head) {
				printf("%d\n", prev->next->val);
				free(prev->next);
				prev->next = NULL;
				break;
			}
			else {
				printf("%d\n", prev->next->val);
				free(prev->next);
				prev->next = NULL;
				prev = head;
				continue;
			}
		}
		else {
			prev = prev->next;
		}
	}
	printf("%d\n", head->val);
	free(head);
	head = NULL;
}
#endif