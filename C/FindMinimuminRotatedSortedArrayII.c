
int findMin(int* nums, int numsSize)
{
	int lo = 0, hi = numsSize - 1;
	if (nums[lo] < nums[hi])
		return nums[lo];
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (nums[mi] == nums[lo])
		{
			int res = findMin(nums + lo + 1, mi - lo);
			if (res < nums[lo])
				return res;
			return findMin(nums + mi + 1, hi - mi);
		}
		if (nums[mi] > nums[lo])
		{
			lo = mi + 1;
			if (nums[lo] < nums[lo - 1])
				break;
		}
		else
			hi = mi;
	}
	return nums[lo];
}
