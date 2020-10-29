
int sumFourDivisors(int* nums, int numsSize)
{
	int res = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		int divisor, count = 0;
		for (int j = 2; j * j <= nums[i] && count <= 1; ++j)
		{
			if (nums[i] % j == 0)
			{
				divisor = j;
				++count;
			}
		}
		if (count == 1 && divisor * divisor != nums[i])
			res += 1 + nums[i] + divisor + nums[i] / divisor;
	}
	return res;
}
