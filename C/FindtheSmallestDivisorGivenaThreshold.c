
int sumQuation(int *num, int size, int n)
{
	int res = 0;
	for (int i = 0; i < size; ++i)
		res += num[i] / n + (num[i] % n ? 1 : 0);
	return res;
}

int smallestDivisor(int *nums, int numsSize, int threshold)
{
	int lo = 1, hi = 1;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] > hi)
			hi = nums[i];
	}

	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (sumQuation(nums, numsSize, mi) > threshold)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}