
int maxProduct(int* nums, int numsSize)
{
	int a = 0, b = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] > a)
		{
			b = a;
			a = nums[i];
		}
		else if (nums[i] > b)
			b = nums[i];
	}
	return (a - 1) * (b - 1);
}
