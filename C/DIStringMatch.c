#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize)
{
	int N = strlen(S);
	*returnSize = N + 1;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int decrease = N, increase = 0;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] == 'I')
			res[i] = increase++;
		else
			res[i] = decrease--;
	}
	res[N] = increase;
	return res;
}
