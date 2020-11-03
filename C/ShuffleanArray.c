#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int *data;
	int *shuffle;
	int size;
} Solution;

Solution *solutionCreate(int *nums, int numsSize)
{
	Solution *res = (Solution *)malloc(sizeof(Solution));
	res->data = nums;
	res->shuffle = (int *)malloc(sizeof(int) * numsSize);
	res->size = numsSize;
	return res;
}

/** Resets the array to its original configuration and return it. */
int *solutionReset(Solution *obj, int *retSize)
{
	*retSize = obj->size;
	return obj->data;
}

/** Returns a random shuffling of the array. */
int *solutionShuffle(Solution *obj, int *retSize)
{
	*retSize = obj->size;
	memcpy(obj->shuffle, obj->data, sizeof(int) * obj->size);
	for (int i = 0; i < obj->size; ++i)
	{
		int index = rand() % (obj->size - i) + i;
		//swap value
		int tmp = obj->shuffle[i];
		obj->shuffle[i] = obj->shuffle[index];
		obj->shuffle[index] = tmp;
	}
	return obj->shuffle;
}

void solutionFree(Solution *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);

 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/
