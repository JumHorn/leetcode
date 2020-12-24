
#define max(a, b) (((a) > (b)) ? (a) : (b))

int arrayNesting(int *nums, int numsSize)
{
	int res = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == -1)
			continue;
		int count = 0;
		for (int index = i; nums[index] != -1;)
		{
			++count;
			int next = nums[index];
			nums[index] = -1;
			index = next;
		}
		res = max(res, count);
	}
	return res;
}