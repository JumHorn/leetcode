
int missingNumber(int* nums, int numsSize)
{
	int res = 0;
	for (int i = 0; i < numsSize; ++i)
		res += nums[i];
	return numsSize * (numsSize + 1) / 2 - res;
}
