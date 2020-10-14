
void reverse(int* nums, int first, int last)  //[first,last)
{
	int i = first - 1, j = last;
	while (++i < --j)
	{
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;
	reverse(nums, 0, numsSize);
	reverse(nums, 0, k);
	reverse(nums, k, numsSize);
}
