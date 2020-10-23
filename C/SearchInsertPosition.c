
int searchInsert(int* nums, int numsSize, int target)
{
	int lo = 0, hi = numsSize;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (nums[mi] < target)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}
