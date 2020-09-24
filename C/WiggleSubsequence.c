
#define max(a, b) (((a) > (b)) ? (a) : (b))

int wiggleMaxLength(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int up = 1, down = 1;
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] > nums[i - 1])
			up = down + 1;
		else if (nums[i] < nums[i - 1])
			down = up + 1;
	}
	return max(up, down);
}
