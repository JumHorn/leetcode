#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strToInt(char *s, int index, int len)
{
	int res = 0;
	for (int i = 0; i < len; ++i)
		res = res * 10 + (s[index + i] - '0');
	return res;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **restoreIpAddresses(char *s, int *returnSize)
{
	static char IP[1000][20];
	memset(IP, 0, sizeof(IP));
	int size = 0, N = strlen(s);
	for (int a = 1; a <= 3; ++a)
		for (int b = 1; b <= 3; ++b)
			for (int c = 1; c <= 3; ++c)
				for (int d = 1; d <= 3; ++d)
					if (a + b + c + d == N)
					{
						int A = strToInt(s, 0, a);
						int B = strToInt(s, a, b);
						int C = strToInt(s, a + b, c);
						int D = strToInt(s, a + b + c, d);
						if (A <= 255 && B <= 255 && C <= 255 && D <= 255)
						{
							sprintf(IP[size], "%d.%d.%d.%d", A, B, C, D);
							if (strlen(IP[size]) == N + 3)
								++size;
						}
					}
	*returnSize = size;
	if (*returnSize == 0)
		return NULL;
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = strdup(IP[i]);
	return res;
}