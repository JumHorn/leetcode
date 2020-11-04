#include <math.h>
#include <stdbool.h>

bool backTracking(double *nums, int n)
{
	if (n == 1 && fabs(nums[0] - 24) < 0.000001)
		return true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			double v[4];
			int size = 0;
			for (int k = 0; k < n; k++) // add leftover nums to v
			{
				if (k != i && k != j)
					v[size++] = nums[k];
			}
			for (int k = 0; k < 4; k++)
			{
				double tmp;
				if (k == 0)
					tmp = nums[i] + nums[j];
				else if (k == 1)
					tmp = nums[i] - nums[j];
				else if (k == 2)
					tmp = nums[i] * nums[j];
				else if (nums[j] != 0)
					tmp = nums[i] / nums[j];

				v[size] = tmp;
				if (backTracking(v, size + 1))
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