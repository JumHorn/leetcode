#include <math.h>
#include <stdbool.h>

bool backTracking(double *nums, int numsSize)
{
	if (numsSize == 1 && fabs(nums[0] - 24) < 0.000001)
		return true;
	for (int i = 0; i < numsSize; ++i)
	{
		for (int j = 0; j < numsSize; ++j)
		{
			if (i == j)
				continue;
			double arr[4];
			int arrSize = 0;
			for (int k = 0; k < numsSize; ++k) // add leftover nums to arr
			{
				if (k != i && k != j)
					arr[arrSize++] = nums[k];
			}
			for (int k = 0; k < 4; ++k)
			{
				double val;
				if (k == 0)
					val = nums[i] + nums[j];
				else if (k == 1)
					val = nums[i] - nums[j];
				else if (k == 2)
					val = nums[i] * nums[j];
				else if (nums[j] != 0)
					val = nums[i] / nums[j];

				arr[arrSize] = val;
				if (backTracking(arr, arrSize + 1))
					return true;
			}
		}
	}
	return false;
}

bool judgePoint24(int *nums, int numsSize)
{
	double dup[numsSize];
	for (int i = 0; i < numsSize; ++i)
		dup[i] = nums[i];
	return backTracking(dup, numsSize);
}