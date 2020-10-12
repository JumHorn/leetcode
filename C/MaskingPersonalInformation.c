#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maskPII(char* S)
{
	char* res = (char*)malloc(sizeof(char) * 100);
	if (isalpha(S[0]))
	{
		int i = 0;
		while (S[i] && S[i] != '@')
			++i;
		sprintf(res, "%c*****%c", tolower(S[0]), tolower(S[i - 1]));
		int j = i;
		while (S[++j])
			S[j] = tolower(S[j]);
		strcpy(&res[7], &S[i]);
	}
	else
	{
		int count = 0, i = strlen(S), j = 19;
		char number[20];
		number[j] = '\0';
		while (--i >= 0)
		{
			if (isdigit(S[i]))
			{
				++count;
				number[--j] = S[i];
			}
		}
		if (count == 11)
			sprintf(res, "+*-***-***-%s", &number[15]);
		else if (count == 12)
			sprintf(res, "+**-***-***-%s", &number[15]);
		else if (count == 13)
			sprintf(res, "+***-***-***-%s", &number[15]);
		else
			sprintf(res, "***-***-%s", &number[15]);
	}
	return res;
}
