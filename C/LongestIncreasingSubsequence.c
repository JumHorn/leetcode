

int lengthOfLIS(int* nums, int numsSize)
{
	int size = 0;
	for (int i = 0; i < numsSize; i++)
	{
		int lo = 0, hi = size;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (nums[mi] < nums[i])
				lo = mi + 1;
			else
				hi = mi;
		}
		nums[lo] = nums[i];
		if (lo == size)
			++size;
	}
	return size;
}
