
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *majorityElement(int *nums, int numsSize, int *returnSize)
{
	int val1, val2, count1 = 0, count2 = 0;
	*returnSize = 0;
	if (numsSize == 0)
		return 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == val1)
			++count1;
		else if (nums[i] == val2)
			++count2;
		else if (count1 == 0)
		{
			val1 = nums[i];
			count1 = 1;
		}
		else if (count2 == 0)
		{
			val2 = nums[i];
			count2 = 1;
		}
		else
		{
			--count1;
			--count2;
		}
	}
	count1 = count2 = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == val1)
			++count1;
		else if (nums[i] == val2)
			++count2;
	}
	*returnSize = (count1 > numsSize / 3 ? 1 : 0) + (count2 > numsSize / 3 ? 1 : 0);
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int index = 0;
	if (count1 > numsSize / 3)
		res[index++] = val1;
	if (count2 > numsSize / 3)
		res[index++] = val2;
	return res;
}