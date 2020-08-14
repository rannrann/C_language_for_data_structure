#ifndef _EIGHT_ZERO_FOUR_
#define _EIGHT_ZERO_FOUR_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*

bool eightZeroFour_contains(char **exist_string, int length, char *string) {
	for (int i = 0; i < length; i++) {
		if (strcmp(exist_string[i],string)==0)
			return true;
	}
	return false;
}

void eightZeroFour_add(char **exist_string, char *string) {
	int i = 0;
	while (strcmp(exist_string[i], "\0") != 0)
		i++;
	strcpy(exist_string[i],string);
}

int uniqueMorseRepresentations(char ** words, int wordsSize) {
	char *morse_cord[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	char **D = (char**)malloc(sizeof(char**)*wordsSize);
	for (int i = 0; i < wordsSize; i++) {
		D[i] = (char*)malloc(sizeof(char*) * 12 * 4);
		strcpy(D[i], "\0");
	}
	int counter = 0;
	for (int i = 0; i < wordsSize; i++)
	{
		char arr[12 * 4]="\0";
		for (int j = 0; j < strlen(words[i]); j++)
		{
			char *ret = morse_cord[(int)(words[i][j]-'a')];//单引号引起的一个字符代表一个整数，对应的是ASCII码
			strcat(arr, ret);
		}
		if (!eightZeroFour_contains(D, wordsSize, arr)) {
			eightZeroFour_add(D, arr);
			counter++;
		}

	}
	for (int i = 0; i < wordsSize; i++) {
		free(D[i]);
		D[i] = NULL;
	}
	free(D);
	D = NULL;
	return counter;
}

*/


/*进阶方法*/
int uniqueMorseRepresentations(char ** words, int wordsSize)
{
	const char *morse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
							"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
							"..-","...-",".--","-..-","-.--","--.." };
	char rep[100][50] = { { 0 } }, c = 0;
	for (int i = 0, j = 0; i < wordsSize; j = 0, i++)
		while (words[i][j] && strcat(rep[i], morse[words[i][j++] - 'a']));
	for (int i = 0, j = i; i < wordsSize; c += j == wordsSize, j = ++i)
		while (++j < wordsSize && strcmp(rep[i], rep[j]));
	return c;
}
#endif