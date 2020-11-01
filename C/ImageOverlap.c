#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

int overlapCount(unsigned int *AA, unsigned int *BB, int size)
{
	int res = 0;
	for (int i = 0; i < size; ++i)
		res += bitCount(AA[i] & BB[i]);
	return res;
}

void translate(unsigned int *v, int vsize, int i, int j, unsigned int *res)
{
	memcpy(res, v, sizeof(unsigned int) * vsize);
	int mask[32];
	for (int k = 0; k < 32; ++k)
		mask[k] = (1u << k) - 1;
	int n = vsize;
	if (i >= 0)
	{
		for (int k = 0; k < n; ++k)
			res[k] >>= i;
	}
	else
	{
		i = -i;
		for (int k = 0; k < n; ++k)
			res[k] = ((res[k] << i) & mask[n]);
	}

	if (j >= 0)
	{
		for (int k = n - j - 1; k >= 0; --k)
			res[k + j] = res[k];
		for (int k = 0; k < j; ++k)
			res[k] = 0;
	}
	else
	{
		j = -j;
		for (int k = j; k < n; ++k)
			res[k - j] = res[k];
		for (int k = n - j; k < n; ++k)
			res[k] = 0;
	}
}

int largestOverlap(int **img1, int img1Size, int *img1ColSize, int **img2, int img2Size, int *img2ColSize)
{
	int n = img1Size;
	unsigned int A[n], B[n];
	memset(A, 0, sizeof(unsigned int) * n);
	memset(B, 0, sizeof(unsigned int) * n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (img1[i][j] == 1)
				A[i] |= 1 << j;
			if (img2[i][j] == 1)
				B[i] |= 1 << j;
		}
	}

	int res = 0;
	for (int i = -(n - 1); i <= (n - 1); ++i)
	{
		for (int j = -(n - 1); j <= (n - 1); ++j)
		{
			unsigned int AA[n];
			translate(A, n, i, j, AA);
			res = max(res, overlapCount(AA, B, n));
		}
	}
	return res;
}