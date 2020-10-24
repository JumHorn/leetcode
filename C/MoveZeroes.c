
void moveZeroes(int* nums, int numsSize)
{
	for (int i = 0, j = 0; j < numsSize; ++i)
	{
		if (i < numsSize)
		{
			if (nums[i] != 0)
				nums[j++] = nums[i];
		}
		else
			nums[j++] = 0;
	}
}
