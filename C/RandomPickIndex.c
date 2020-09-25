#include <math.h>
#include <stdlib.h>

/*
Algorithm:
Reservoir Sampling
*/

typedef struct
{
	int *data;
	int size;
} Solution;

Solution *solutionCreate(int *nums, int numsSize)
{
	Solution *res = (Solution *)malloc(sizeof(Solution));
	res->data = nums;
	res->size = numsSize;
	return res;
}

int solutionPick(Solution *obj, int target)
{
	int count = 0, res = 0;
	for (int i = 0; i < obj->size; ++i)
	{
		if (obj->data[i] == target)
		{
			if (rand() % ++count == 0)
				res = i;
		}
	}
	return res;
}

void solutionFree(Solution *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);

 * solutionFree(obj);
*/