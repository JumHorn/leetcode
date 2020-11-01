
int minStartValue(int* nums, int numsSize)
{
	int sum = 1, startValue = 1;
	for (int i = 0; i < numsSize; ++i)
	{
		sum += nums[i];
		if (sum < 1)
		{
			startValue += 1 - sum;
			sum = 1;
		}
	}
	return startValue;
}
