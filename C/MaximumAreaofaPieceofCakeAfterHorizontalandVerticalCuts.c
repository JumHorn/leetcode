#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int arrMax(int *arr, int arrSize)
{
	if (arrSize == 0)
		return 0;
	int res = arr[0];
	for (int i = 1; i < arrSize; ++i)
	{
		if (arr[i] > res)
			res = arr[i];
	}
	return res;
}

int maxArea(int h, int w, int *horizontalCuts, int horizontalCutsSize, int *verticalCuts, int verticalCutsSize)
{
	static const int MOD = 1e9 + 7;
	int H[horizontalCutsSize + 1], V[verticalCutsSize + 1];
	qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmp);
	H[horizontalCutsSize] = h - horizontalCuts[horizontalCutsSize - 1];
	H[0] = horizontalCuts[0];
	for (int i = horizontalCutsSize - 1; i > 0; --i)
		H[i] = horizontalCuts[i] - horizontalCuts[i - 1];
	qsort(verticalCuts, verticalCutsSize, sizeof(int), cmp);
	V[verticalCutsSize] = w - verticalCuts[verticalCutsSize - 1];
	V[0] = verticalCuts[0];
	for (int i = verticalCutsSize - 1; i > 0; --i)
		V[i] = verticalCuts[i] - verticalCuts[i - 1];
	long width = arrMax(H, horizontalCutsSize + 1);
	long height = arrMax(V, verticalCutsSize + 1);
	return (width % MOD) * (height % MOD) % MOD;
}