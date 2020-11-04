
#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestSubarray(int* nums, int numsSize)
{
	int d0 = 0, d1 = -1, res = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == 0)
		{
			d1 = d0;
			d0 = 0;
		}
		else
		{
			d1 = max(d1 + 1, d0);
			d0 = d0 + 1;
		}
		res = max(res, d1);
	}
	return res;
}
