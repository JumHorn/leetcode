
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int top = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] != nums[top])
			nums[++top] = nums[i];
	}
	return top + 1;
}
