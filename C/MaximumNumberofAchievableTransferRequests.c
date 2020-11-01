#include <stdbool.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

bool equalArr(int *lhs, int *rhs, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

int maximumRequests(int n, int **requests, int requestsSize, int *requestsColSize)
{
	int res = 0;
	for (int mask = 0; mask < 1 << requestsSize; ++mask)
	{
		int indegree[21] = {0}, outdegree[21] = {0};
		for (int i = 0; i < requestsSize; ++i)
		{
			if ((1 << i) & mask)
			{
				++outdegree[requests[i][0]];
				++indegree[requests[i][1]];
			}
		}
		if (equalArr(indegree, outdegree, n))
		{
			int val = bitCount(mask);
			res = max(res, val);
		}
	}
	return res;
}