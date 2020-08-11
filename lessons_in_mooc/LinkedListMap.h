#ifndef _LINKED_LIST_MAP_
#define _LINKED_LIST_MAP_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define K LinkedListMap_K
typedef struct K *K;
#define V LinkedListMap_V
typedef struct V *V;


typedef struct llmNode llmNode;
struct llmNode {
	K *key;
	V *value;
	llmNode *next;
	llmNode* create_llmNode(K* key, V *value, llmNode *next) {
		llmNode *llm = NULL;
		llm = (llmNode*)malloc(sizeof(llmNode));
		llm->key = key;
		llm->value = value;
		llm->next = next;
		return llm;
	}

	llmNode* create_llmNode_only_key(K* key) {
		llmNode *llm = NULL;
		llm = (llmNode*)malloc(sizeof(llmNode));
		llm->key = key;
		llm->value = NULL;
		llm->next = NULL;
		return llm;
	}


	llmNode* create_llmNode_nothing() {
		llmNode *llm = NULL;
		llm = (llmNode*)malloc(sizeof(llmNode));
		llm->key = NULL;
		llm->value = NULL;
		llm->next = NULL;
		return llm;
	}

	void release_linked_list_map(llmNode *llm) {

	}
};





#endif

