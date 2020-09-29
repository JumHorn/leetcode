

int findTargetSumWays(int* nums, int numsSize, int S)
{
	if (numsSize == 0)
		return S == 0 ? 1 : 0;
	int res = 0;
	if ((long)S - *nums >= -1000)
		res += findTargetSumWays(nums + 1, numsSize - 1, S - *nums);
	if ((long)S + *nums <= 1000)
		res += findTargetSumWays(nums + 1, numsSize - 1, S + *nums);
	return res;
}
