#ifndef _ONE_THREE_ZERO_NINE_
#define _ONE_THREE_ZERO_NINE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
char * freqAlphabets(char * s) {

	char longest[1000] = { 0 };
	char re[1000] = { 0 };
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '#')
			longest[i - 2] = s[i];
	}
	for (int i = 0,j=i; i < strlen(s);j++)
	{
		if (longest[i] == '#')
		{
			re[j] = (s[i] - '0') * 10 + s[i + 1] - '1' + 'a';
			i += 3;
		}
			
		else
		{
			re[j] = s[i] - '1' + 'a';
			i++;
		}
			
	}
	return re;
}
#endif