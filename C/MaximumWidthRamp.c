#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxWidthRamp(int *A, int ASize)
{
	int *arr = (int *)malloc(ASize * sizeof(int));
	int *index = (int *)malloc(ASize * sizeof(int));
	int res = 0, top = 0;
	arr[top] = A[0];
	index[top] = 0;
	for (int i = 1; i < ASize; i++)
	{
		if (A[i] < arr[top])
		{
			arr[++top] = A[i];
			index[top] = i;
		}
		else
		{
			if (A[i] >= arr[0])
				res = max(res, i - 0);
			else
			{
				int lo = 0, hi = top;
				while (lo < hi)
				{
					int mi = (hi - lo) / 2 + lo;
					if (arr[mi] > A[i])
						lo = mi + 1;
					else
						hi = mi;
				}
				res = max(res, i - index[lo]);
			}
		}
	}
	return res;
}