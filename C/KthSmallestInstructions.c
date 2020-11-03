#include <stdlib.h>
#include <string.h>

int combination(int n, int m)
{
	int res = 1;
	for (int i = 1; i <= m; ++i)
		res = res * (n - m + i) / i;
	return res;
}

char* kthSmallestPath(int* destination, int destinationSize, int k)
{
	int H = destination[1], V = destination[0], N = H + V;
	char* res = (char*)malloc(sizeof(char) * (N + 1));
	res[N] = '\0';
	memset(res, 'V', sizeof(char) * N);
	for (int i = 0; i < N && H > 0; ++i)
	{
		int count = combination(H + V - 1, V);
		if (k > count)
		{
			--V;
			k -= count;
		}
		else
		{
			--H;
			res[i] = 'H';
		}
	}
	return res;
}
