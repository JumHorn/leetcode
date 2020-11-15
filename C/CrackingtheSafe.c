#include <math.h>
#include <string.h>

/*
Inverse Burrows-Wheeler Transform(IBWT)
Fredericksen and Maiorana
*/

char *crackSafe(int n, int k)
{
	int M = pow(k, n - 1);
	int P[M * k];
	for (int i = 0; i < k; ++i)
	{
		for (int q = 0; q < M; ++q)
			P[i * M + q] = q * k + i;
	}

	char res[5000];
	int resSize = 0;
	for (int i = 0; i < M * k; ++i)
	{
		for (int j = i; P[j] >= 0;)
		{
			res[resSize++] = j / M + '0';
			int v = P[j];
			P[j] = -1;
			j = v;
		}
	}
	for (int i = 0; i < n - 1; ++i)
		res[resSize++] = '0';
	res[resSize] = '\0';
	return strdup(res);
}