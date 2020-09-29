#include <stdlib.h>

typedef struct
{
	int **rects;
	int rectsSize;
	int *rectsColSize;
	int *prefixsum;
	int maxpoint;
} Solution;

Solution *solutionCreate(int **rects, int rectsSize, int *rectsColSize)
{
	Solution *res = (Solution *)malloc(sizeof(Solution));
	res->rects = rects;
	res->rectsSize = rectsSize;
	res->rectsColSize = rectsColSize;
	res->prefixsum = (int *)malloc(sizeof(int) * (rectsSize + 1));
	res->prefixsum[0] = 0;
	for (int i = 0; i < rectsSize; ++i)
		res->prefixsum[i + 1] = res->prefixsum[i] + (rects[i][3] - rects[i][1] + 1) * (rects[i][2] - rects[i][0] + 1);
	res->maxpoint = res->prefixsum[rectsSize];
	return res;
}

int *solutionPick(Solution *obj, int *retSize)
{
	*retSize = 2;
	int *res = (int *)malloc(sizeof(int) * (*retSize));
	int r = rand() % obj->maxpoint, lo = 0, hi = obj->rectsSize + 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (obj->prefixsum[mi] <= r)
			lo = mi + 1;
		else
			hi = mi;
	}
	r -= obj->prefixsum[lo - 1];
	int *rect = obj->rects[lo - 1], side = rect[2] - rect[0] + 1;
	res[0] = rect[0] + r % side;
	res[1] = rect[1] + r / side;
	return res;
}

void solutionFree(Solution *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(rects, rectsSize, rectsColSize);
 * int* param_1 = solutionPick(obj, retSize);

 * solutionFree(obj);
*/