
int search(int* nums, int numsSize, int target)
{
	if (numsSize == 0)
		return -1;
	int lo = 0, hi = numsSize - 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (nums[mi] < target)
			lo = mi + 1;
		else
			hi = mi;
	}
	return nums[lo] == target ? lo : -1;
}
