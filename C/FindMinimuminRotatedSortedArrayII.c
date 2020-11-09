
int findMin(int *nums, int numsSize)
{
	int lo = 0, hi = numsSize - 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (nums[mi] > nums[hi])
			lo = mi + 1;
		else if (nums[mi] < nums[hi])
			hi = mi;
		else // when num[mid] and num[hi] are same
			--hi;
	}
	return nums[lo];
}