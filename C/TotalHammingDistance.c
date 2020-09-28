

int totalHammingDistance(int* nums, int numsSize)
{
	int res = 0;
	for (int i = 0; i <= 30; ++i)
	{
		int ones = 0;
		for (int j = 0; j < numsSize; ++j)
			ones += ((nums[j] >> i) & 1);
		res += ones * (numsSize - ones);
	}
	return res;
}
