

bool checkSubarraySum(int* nums, int numsSize, int k)
{
	for (int i = 0; i < numsSize - 1; i++)
		nums[i + 1] += nums[i];
	for (int i = 0; i < numsSize - 1; i++)
		for (int j = i + 1; j < numsSize; j++)
		{
			if (k == 0)
			{
				if (nums[j] - (i > 0 ? nums[i - 1] : 0) == 0)
					return true;
			}
			else if ((nums[j] - (i > 0 ? nums[i - 1] : 0)) % k == 0)
				return true;
		}
	return false;
}

