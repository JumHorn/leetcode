#include <stdbool.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool isIdealPermutation(int *A, int ASize)
{
	int premax = 0;
	for (int i = 0; i < ASize - 2; ++i)
	{
		premax = max(premax, A[i]);
		if (premax > A[i + 2])
			return false;
	}
	return true;
}