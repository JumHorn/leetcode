
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxProduct(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int maxproduct = 1, minproduct = 1, res = nums[0];
	for (int i = 0; i < numsSize; ++i)
	{
		int maxproduct1 = max(maxproduct * nums[i], minproduct * nums[i]);
		maxproduct1 = max(maxproduct1, nums[i]);
		int minproduct1 = min(maxproduct * nums[i], minproduct * nums[i]);
		minproduct1 = min(minproduct1, nums[i]);
		maxproduct = nums[i] == 0 ? 1 : maxproduct1;
		minproduct = nums[i] == 0 ? 1 : minproduct1;
		res = max(res, maxproduct1);
	}
	return res;
}
