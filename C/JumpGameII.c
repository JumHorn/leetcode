
#define max(a, b) (((a) > (b)) ? (a) : (b))

int jump(int *nums, int numsSize)
{
	int res = 0, curEnd = 0, curFarthest = 0;
	for (int i = 0; i < numsSize - 1; ++i)
	{
		curFarthest = max(curFarthest, i + nums[i]);
		if (i == curEnd)
		{
			++res;
			curEnd = curFarthest;
		}
	}
	return res;
}