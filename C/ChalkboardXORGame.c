#include <stdbool.h>

bool xorGame(int *nums, int numsSize)
{
	int XOR = 0;
	for (int i = 0; i < numsSize; ++i)
		XOR ^= nums[i];
	return XOR == 0 || numsSize % 2 == 0;
}