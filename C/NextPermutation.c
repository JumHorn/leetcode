
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

void reverse(int *arr, int first, int last)
{
	while (first < last)
	{
		swap(arr[first], arr[last]);
		++first;
		--last;
	}
}

void nextPermutation(int *nums, int numsSize)
{
	int i = numsSize;
	while (--i > 0)
	{
		if (nums[i] > nums[i - 1])
		{
			int j = i;
			while (j < numsSize && nums[j] > nums[i - 1])
				++j;
			swap(nums[i - 1], nums[j - 1]);
			reverse(nums, i, numsSize - 1);
			return;
		}
	}
	reverse(nums, 0, numsSize - 1);
}