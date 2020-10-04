#include <stdbool.h>

bool backTracking(int* nums, int numsSize, int index, int k, int sub, int sum)
{
	if (k == 1)
		return true;
	if (sub == 0)
		return backTracking(nums, numsSize, 0, k - 1, sum, sum);
	for (int i = index; i < numsSize; ++i)
	{
		if (nums[i] < 0)
			continue;
		nums[i] = -nums[i];
		if (sub + nums[i] >= 0 && backTracking(nums, numsSize, i + 1, k, sub + nums[i], sum))
			return true;
		nums[i] = -nums[i];
	}
	return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k)
{
	int sum = 0;
	for (int i = 0; i < numsSize; ++i)
		sum += nums[i];
	if (sum % k != 0)
		return false;
	sum /= k;
	return backTracking(nums, numsSize, 0, k, sum, sum);
}
