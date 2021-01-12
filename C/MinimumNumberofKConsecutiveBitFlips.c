#include <string.h>

int minKBitFlips(int *A, int ASize, int K)
{
	int flip[ASize + 1], flag = 0, res = 0;
	memset(flip, 0, sizeof(flip));
	for (int i = 0; i < ASize; ++i)
	{
		if (flip[i] == 1)
			flag = 1 ^ flag;
		if ((flag ^ A[i]) == 0)
		{
			++res;
			flag = 1 ^ flag;
			if (i + K > ASize)
				return -1;
			flip[i + K] = 1 ^ flip[i + K];
		}
	}
	return res;
}