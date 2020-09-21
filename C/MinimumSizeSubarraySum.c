
#define min(a, b) (((a) < (b)) ? (a) : (b))

int binarySeach(int* arr, int lo, int hi, int val)
{
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] <= val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo - 1;
}

int minSubArrayLen(int s, int* nums, int numsSize)
{
	int res = numsSize;
	for (int i = 1; i < numsSize; ++i)
		nums[i] += nums[i - 1];
	if (numsSize == 0 || nums[numsSize - 1] < s)
		return 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] < s)
			continue;
		int preindex = -1;
		if (nums[i] - s >= nums[0])
			preindex = binarySeach(nums, 0, i, nums[i] - s);
		res = min(res, i - preindex);
	}
	return res;
}
