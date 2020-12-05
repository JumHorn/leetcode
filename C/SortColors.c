
// counting sort
void sortColors(int *nums, int numsSize)
{
	int count[3] = {0};
	for (int i = 0; i < numsSize; ++i)
		++count[nums[i]];
	for (int i = 0, j = 0; i < numsSize;)
	{
		if (count[j] > 0)
		{
			--count[j];
			nums[i++] = j;
		}
		else
			++j;
	}
}