
#define max(a, b) (((a) > (b)) ? (a) : (b))

int findLengthOfLCIS(int* nums, int numsSize)
{
	int res = 0;
	for (int i = 1, j = 0; i <= numsSize; ++i)
	{
		if (i == numsSize || nums[i - 1] >= nums[i])
		{
			res = max(res, i - j);
			j = i;
		}
	}
	return res;
}
