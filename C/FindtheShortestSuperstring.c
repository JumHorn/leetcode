#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int overlap(char* a, char* b)
{
	int k = 0, len_a = strlen(a), len_b = strlen(b);
	int m = min(len_a, len_b);
	for (k = m; k > 0; --k)
	{
		int i = len_a - k, j = 0;
		while (j < k && a[i++] == b[j])
			++j;
		if (j == k)
			break;
	}
	return k;
}

char* shortestSuperstring(char** A, int ASize)
{
	int graph[ASize][ASize];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = 0; j < ASize; ++j)
		{
			if (i == j)
				continue;
			graph[i][j] = overlap(A[i], A[j]);
		}
	}

	//TSP DP build maximum overlap
	int dp[1 << ASize][ASize];
	memset(dp, 0, sizeof(dp));
	int path[1 << ASize][ASize];
	memset(path, -1, sizeof(path));
	for (int mask = 0; mask < (1 << ASize); ++mask)
	{
		for (int bit = 0; bit < ASize; ++bit)
		{
			if (!((mask >> bit) & 1))
				continue;
			int premask = mask ^ (1 << bit);
			if (premask == 0)
				continue;
			for (int i = 0; i < ASize; ++i)
			{
				if ((premask >> i) & 1)
				{
					int val = dp[premask][i] + graph[i][bit];
					if (val > dp[mask][bit])
					{
						dp[mask][bit] = val;
						path[mask][bit] = i;
					}
				}
			}
		}
	}

	int max = 0, mask = (1 << ASize) - 1;
	for (int i = 1; i < ASize; ++i)
	{
		if (dp[mask][i] > dp[mask][max])
			max = i;
	}
	int stack[ASize], index = ASize, seen[ASize];  //store result order
	memset(seen, 0, sizeof(seen));
	while (max != -1)
	{
		stack[--index] = max;
		seen[max] = 1;
		int tmp = path[mask][max];
		mask ^= 1 << max;
		max = tmp;
	}
	for (int i = 0; i < ASize; ++i)
	{
		if (seen[i] == 0)
			stack[--index] = i;
	}
	char* res = (char*)malloc(sizeof(char) * 300);
	memset(res, 0, sizeof(char) * 300);
	strcat(res, A[stack[0]]);
	for (int i = 1; i < ASize; ++i)
		strcat(res, A[stack[i]] + graph[stack[i - 1]][stack[i]]);
	return res;
}
