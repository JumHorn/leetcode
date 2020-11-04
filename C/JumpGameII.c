
int jump(int *nums, int numsSize)
{
	if (numsSize <= 1)
		return 0;
	int res = 1, maxright = nums[0], i = 0;
	while (maxright < numsSize - 1)
	{
		++res;
		int right = maxright;
		for (int j = i + 1; j <= maxright; ++j)
			if (right < nums[j] + j)
				right = nums[j] + j;
		i = maxright;
		maxright = right;
	}
	return res;
}