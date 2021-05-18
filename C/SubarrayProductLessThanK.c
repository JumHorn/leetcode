
int numSubarrayProductLessThanK(int *nums, int numsSize, int k)
{
	int res = 0, product = 1;
	for (int i = 0, j = 0; i < numsSize; ++i)
	{
		product *= nums[i];
		for (; j <= i && product >= k; ++j)
			product /= nums[j];
		res += i - j + 1;
	}
	return res;
}