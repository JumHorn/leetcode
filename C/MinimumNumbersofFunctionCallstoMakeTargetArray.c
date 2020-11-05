
int minOperations(int* nums, int numsSize)
{
	int maxbit = 1, res = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		int bits = 0;
		while (nums[i] > 0)
		{
			res += nums[i] & 1;
			++bits;
			nums[i] >>= 1;
		}
		if (maxbit < bits)
			maxbit = bits;
	}
	return res + maxbit - 1;
}
