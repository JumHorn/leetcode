
/*
Boyer–Moore majority vote algorithm
*/

int majorityElement(int *nums, int numsSize)
{
	int val = 0, count = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (val == nums[i])
			++count;
		else if (count == 0)
		{
			val = nums[i];
			count = 1;
		}
		else
			--count;
	}
	return val;
}