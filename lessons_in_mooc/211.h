#ifndef _TWO_ONE_ONE_
#define _TWO_ONE_ONE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define LEN 26
int tmp2[500] = { 0 };


typedef struct WordDictionary WordDictionary;

struct WordDictionary {
	bool is_word;
	WordDictionary **next;
};

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
	WordDictionary* obj = (WordDictionary*)malloc(sizeof(WordDictionary));
	obj->is_word = false;
	int space = sizeof(WordDictionary*)*LEN;
	obj->next = (WordDictionary**)malloc(space);
	memset(obj->next, 0, space);
	return obj;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
	int i;
	for (i = 0; word[i]; i++) {
		int nIndex = word[i] - 'a';
		if (!(obj->next[nIndex]))
			obj->next[nIndex] = wordDictionaryCreate();
		obj = obj->next[nIndex];
	}
	tmp2[i - 1] = 1;
	obj->is_word = true;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */

bool recursiveSearch(WordDictionary *obj, int target, int layer) {
	if (layer == 0) {
		if (obj->next[target - 'a'] != NULL)
			return true;
		else
			return false;
	}

	for (int i = 0; i < LEN; i++) {
		if (obj->next[i]) {
			if (recursiveSearch(obj->next[i], target, layer - 1))
				return true;
		}

	}

	return false;

}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
	int tmp3[500] = { 0 };


	int i;
	for (i = 0; word[i]; i++) {
		if (word[i] != '.')
			tmp3[i] = 1;
	}
	for (int j = 0; j < i; j++) {
		if (tmp3[j] > 0)
		{
			if (!recursiveSearch(obj, (int)word[j], j))
				return false;
		}

	}
	if (tmp2[i - 1] > 0)
		return true;
	else
		return false;
}


void wordDictionaryFree(WordDictionary* obj) {
	free(obj->next);
	free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);

 * bool param_2 = wordDictionarySearch(obj, word);

 * wordDictionaryFree(obj);
*/



#endif