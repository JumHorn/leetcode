
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
	*returnSize = ASize;
	for (int odd = 1, even = 0; odd < ASize && even < ASize;)
	{
		if (A[odd] % 2 == 1)
			odd += 2;
		else if (A[even] % 2 == 0)
			even += 2;
		else
		{
			swap(A[odd], A[even]);
			odd += 2;
			even += 2;
		}
	}
	return A;
}
