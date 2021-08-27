#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

int maxLength(char **arr, int arrSize)
{
	int maskArr[1 << 16] = {0}, maskArrSize = 1, res = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		int mask = 0;
		for (int j = 0; arr[i][j]; ++j)
		{
			if (mask & (1 << (arr[i][j] - 'a')))
				break;
			mask |= 1 << (arr[i][j] - 'a');
		}
		if (mask == 0)
			continue;
		int N = maskArrSize;
		for (int j = 0; j < N; ++j)
		{
			if ((mask & maskArr[j]) == 0)
			{
				maskArr[maskArrSize++] = (mask | maskArr[j]);
				int bit = bitCount(mask | maskArr[j]);
				res = max(res, bit);
			}
		}
	}
	return res;
}