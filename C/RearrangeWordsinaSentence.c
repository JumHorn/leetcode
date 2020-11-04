#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair
{
	char* word;
	int len;
	int index;
} pair;

int cmp(const void* lhs, const void* rhs)
{
	pair *l = (pair*)lhs, *r = (pair*)rhs;
	if (l->len != r->len)
		return l->len - r->len;
	return l->index - r->index;
}

char* arrangeWords(char* text)
{
	int N = strlen(text), arrSize = 0, resSize = 0;
	pair arr[N];
	for (char* token = strtok(text, " "); token; token = strtok(NULL, " "))
	{
		arr[arrSize].word = token;
		arr[arrSize].len = strlen(token);
		arr[arrSize].index = arrSize;
		++arrSize;
	}
	arr[0].word[0] = tolower(arr[0].word[0]);
	qsort(arr, arrSize, sizeof(pair), cmp);
	char* res = (char*)malloc(sizeof(char) * (N + 1));
	res[N] = '\0';
	resSize = sprintf(res, "%s", arr[0].word);
	for (int i = 1; i < arrSize; ++i)
		resSize += sprintf(&res[resSize], " %s", arr[i].word);
	res[0] = toupper(res[0]);
	return res;
}
