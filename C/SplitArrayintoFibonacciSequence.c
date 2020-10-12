#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool backTracking(char* S, int index, int* fib, int* fibSize)
{
	long num = 0;
	if (!S[index])
		return *fibSize >= 3;
	for (int i = index; S[i]; ++i)
	{
		if (S[index] == '0' && i != index)
			break;
		num = num * 10 + S[i] - '0';
		if (num > INT_MAX)
			break;
		if (*fibSize >= 2 && num != (long)fib[*fibSize - 1] + fib[*fibSize - 2])
			continue;
		fib[(*fibSize)++] = num;
		if (backTracking(S, i + 1, fib, fibSize))
			return true;
		--*fibSize;
		if (*fibSize >= 2)
			break;
	}
	return false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* splitIntoFibonacci(char* S, int* returnSize)
{
	int fib[200];
	*returnSize = 0;
	if (!backTracking(S, 0, fib, returnSize))
		return NULL;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	memcpy(res, fib, sizeof(int) * (*returnSize));
	return res;
}
