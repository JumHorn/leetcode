/*
algorithm:
slide window
*/

int numberOfSubarrays(int* nums, int numsSize, int k)
{
	int res = 0, odd = 0;
	if (k > numsSize)
		return res;
	int i = 0, j = 0;
	for (; i < numsSize && odd < k; ++i)
		odd += nums[i] % 2;
	if (odd == k)
		--i;
	while (i < numsSize)
	{
		int right = i + 1;
		while (right < numsSize && nums[right] % 2 != 1)
			++right;
		int left = j;
		while (left < numsSize && nums[left] % 2 != 1)
			++left;
		res += (left - j + 1) * (right - i);
		i = right;
		j = left + 1;
	}
	return res;
}
