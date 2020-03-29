
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

int firstMissingPositive(int *nums, int numsSize)
{
	for (int i = 0; i < numsSize; i++)
	{
		while (i + 1 != nums[i])
		{
			if (nums[i] <= 0)
				break;
			int j = nums[i] - 1;
			if (j >= numsSize || nums[j] == j + 1)
				break;
			swap(nums[i], nums[j]);
		}
	}
	for (int i = 0; i < numsSize; i++)
		if (nums[i] != i + 1)
			return i + 1;
	return numsSize + 1;
}
