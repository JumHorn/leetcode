
int numIdenticalPairs(int* nums, int numsSize)
{
	int count[101] = {0}, res = 0;
	for (int i = 0; i < numsSize; ++i)
		++count[nums[i]];
	for (int i = 0; i < 101; ++i)
		res += count[i] * (count[i] - 1) / 2;
	return res;
}
