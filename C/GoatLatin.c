#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toGoatLatin(char *S)
{
	char vowel[] = "aeiouAEIOU";
	int hash['z' - 'A' + 1] = {0};
	for (int i = 0; vowel[i]; ++i)
		hash[vowel[i] - 'A'] = 1;
	char *res = (char *)malloc(sizeof(char) * 20000);
	int aaa = 1, resSize = 0;
	for (char *token = strtok(S, " "); token; token = strtok(NULL, " "))
	{
		if (hash[token[0] - 'A'] == 1)
			resSize += sprintf(&res[resSize], " %sma", token);
		else
			resSize += sprintf(&res[resSize], " %s%cma", &token[1], token[0]);
		memset(&res[resSize], 'a', sizeof(char) * aaa);
		resSize += aaa++;
	}
	res[resSize] = '\0';
	return &res[1];
}