
#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

void reverse(int *arr, int first, int last)
{
	for (; first < last; ++first, --last)
		swap(arr[first], arr[last]);
}

void nextPermutation(int *nums, int numsSize)
{
	for (int i = numsSize - 1; i > 0; --i)
	{
		if (nums[i] > nums[i - 1])
		{
			int j = numsSize - 1;
			while (nums[j] <= nums[i - 1])
				--j;
			swap(nums[i - 1], nums[j]);
			reverse(nums, i, numsSize - 1);
			return;
		}
	}
	reverse(nums, 0, numsSize - 1);
}