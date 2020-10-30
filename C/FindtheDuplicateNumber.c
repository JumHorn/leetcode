
void swap(int *lhs, int *rhs)
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

int findDuplicate(int *nums, int numsSize)
{
	for (int i = 0; i < numsSize;)
	{
		if (nums[i] < i + 1 || (nums[i] != i + 1 && nums[nums[i] - 1] == nums[i]))
			return nums[i];
		if (nums[i] > i + 1)
			swap(&nums[nums[i] - 1], &nums[i]);
		else
			++i;
	}
	return numsSize;
}