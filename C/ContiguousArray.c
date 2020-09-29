#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int findMaxLength(int* nums, int numsSize)
{
	int res = 0, diff = 0;  //count(1)-count(0)
	int hash[2 * numsSize + 1];
	memset(hash, 1u << 7, sizeof(hash));
	hash[numsSize] = -1;
	for (int i = 0; i < numsSize; ++i)
	{
		nums[i] ? ++diff : --diff;
		if (hash[diff + numsSize] >= -1)
			res = max(res, i - hash[diff + numsSize]);
		else
			hash[diff + numsSize] = i;
	}
	return res;
}
