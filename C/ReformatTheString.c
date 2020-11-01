#include <math.h>
#include <stdbool.h>

char* reformat(char* s)
{
	char num[500], alpha[500];
	int numSize = 0, alphaSize = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			num[numSize++] = s[i];
		else
			alpha[alphaSize++] = s[i];
	}
	if (abs(numSize - alphaSize) > 1)
		return "";
	bool flag = numSize > alphaSize;
	for (int i = 0; s[i]; ++i)
	{
		if (flag)
			s[i] = num[--numSize];
		else
			s[i] = alpha[--alphaSize];
		flag = !flag;
	}
	return s;
}
