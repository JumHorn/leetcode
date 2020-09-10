#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
	if (numRows <= 1)
		return s;
	int N = strlen(s), T = 2 * numRows - 2;
	char* res = (char*)malloc(sizeof(char) * (N + 1));
	res[N] = '\0';
	for (int i = 0, k = 0; i < numRows; ++i)
	{
		for (int j = 0; j + i < N; j += T)
		{
			res[k++] = s[j + i];
			if (i != 0 && i != numRows - 1 && j + T - i < N)
				res[k++] = s[j + T - i];
		}
	}
	return res;
}
