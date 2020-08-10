#ifndef _EIGHT_ZERO_FOUR_
#define _EIGHT_ZERO_FOUR_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
char* find_index_return_mode(char letter) {
	char * ret;
	switch (letter) {

	case 'a':ret = (char *)".-"; return ret;
	case 'b':ret = (char *) "-..."; return ret;
	case 'c':ret = (char *)  "-.-."; return ret;
	case 'd':ret = (char *)  "-.."; return ret;
	case 'e':ret = (char *)  "."; return ret;
	case 'f':ret = (char *)  "..-."; return ret;
	case 'g':ret = (char *)  "--."; return ret;
	case 'h':ret = (char *)  "...."; return ret;
	case 'i':ret = (char *)  ".."; return ret;
	case 'j':ret = (char *)  ".---"; return ret;
	case 'k':ret = (char *)  "-.-"; return ret;
	case 'l':ret = (char *)  ".-.."; return ret;
	case 'm':ret = (char *)  "--"; return ret;
	case 'n':ret = (char *)  "-."; return ret;
	case 'o':ret = (char *)  "---"; return ret;
	case 'p':ret = (char *)  ".--."; return ret;
	case 'q':ret = (char *)  "--.-"; return ret;
	case 'r':ret = (char *)  ".-."; return ret;
	case 's':ret = (char *)  "..."; return ret;
	case 't':ret = (char *)  "-"; return ret;
	case 'u':ret = (char *)  "..-"; return ret;
	case 'v':ret = (char *)  "...-"; return ret;
	case 'w':ret = (char *)  ".--"; return ret;
	case 'x':ret = (char *)  "-..-"; return ret;
	case 'y':ret = (char *)  "-.--"; return ret;
	case 'z':ret = (char *)  "--.."; return ret;

	}
	return NULL;
}

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
			char *ret = find_index_return_mode(words[i][j]);
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
#endif