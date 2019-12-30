
int sumQuation(int *num, int size, int n)
{
	int res = 0;
	for (int i = 0; i < size; i++)
		res += num[i] / n + (num[i] % n ? 1 : 0);
	return res;
}

int smallestDivisor(int *nums, int numsSize, int threshold)
{
	int lo = 1, hi = 1, mi = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (mi < threshold)
			mi += nums[i];
		if (nums[i] > hi)
			hi = nums[i];
	}
	if (threshold == 1)
		return hi;
	if (threshold >= mi)
		return 1;

	while (lo < hi)
	{
		mi = (hi - lo) / 2 + lo;
		int tmp = sumQuation(nums, numsSize, mi);
		if (tmp <= threshold)
			hi = mi;
		else
			lo = mi + 1;
	}
	return lo;
}