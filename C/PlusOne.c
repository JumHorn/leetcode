#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int carry = 1;
	for (int i = digitsSize - 1; i >= 0; --i)
	{
		carry += digits[i];
		digits[i] = carry % 10;
		carry /= 10;
	}
	*returnSize = digitsSize + carry;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(&res[carry], digits, sizeof(int) * digitsSize);
	if (carry == 0)
		return res;
	res[0] = 1;
	return res;
}