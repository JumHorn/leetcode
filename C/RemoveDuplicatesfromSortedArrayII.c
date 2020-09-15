

int removeDuplicates(int* nums, int numsSize)
{
	int res = 0, i = 0, j = 0;
	if (numsSize == 0)
		return 0;
	do
	{
		++i;
		if (i >= numsSize || nums[i] != nums[j])
		{
			for (int k = j; k < i && k < j + 2; ++k)
				nums[res++] = nums[k];
			j = i;
		}
	} while (i < numsSize);
	return res;
}
