#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int sumSubseqWidths(int *A, int ASize)
{
	static const int MOD = 1e9 + 7;
	qsort(A, ASize, sizeof(int), cmp);
	long res = 0, pow2 = 1;
	for (int i = 0; i < ASize; ++i)
	{
		res = (res + A[i] * pow2 - A[ASize - i - 1] * pow2) % MOD;
		pow2 = pow2 * 2 % MOD;
	}
	return (res + MOD) % MOD;
}