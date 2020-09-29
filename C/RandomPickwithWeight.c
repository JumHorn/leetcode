#include <stdlib.h>

typedef struct
{
	int* prefixsum;
	int size;
	int sum;
} Solution;

Solution* solutionCreate(int* w, int wSize)
{
	Solution* res = (Solution*)malloc(sizeof(Solution));
	res->size = wSize + 1;
	res->prefixsum = (int*)malloc(sizeof(int) * res->size);
	res->prefixsum[0] = 0;
	for (int i = 0; i < wSize; ++i)
		res->prefixsum[i + 1] = res->prefixsum[i] + w[i];
	res->sum = res->prefixsum[wSize];
	return res;
}

int solutionPickIndex(Solution* obj)
{
	int pick = rand() % obj->sum + 1;
	int lo = 0, hi = obj->size;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (pick > obj->prefixsum[mi])
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo - 1;
}

void solutionFree(Solution* obj)
{
	if (obj)
	{
		if (obj->prefixsum)
			free(obj->prefixsum);
		free(obj);
	}
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/
