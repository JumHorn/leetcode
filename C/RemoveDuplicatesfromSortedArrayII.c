
int removeDuplicates(int *nums, int numsSize)
{
	int res = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (res < 2 || nums[i] > nums[res - 2])
			nums[res++] = nums[i];
	}
	return res;
}