
int missingNumber(int* nums, int numsSize)
{
	int res = 0;
	for (int i = 0; i < numsSize; ++i)
		res ^= i ^ nums[i];
	return res ^ numsSize;
}
