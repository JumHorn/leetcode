#include <math.h>

int dfs(int *digits, int size, int *arrN, int index)
{
	if (index < 0)
		return 1;
	int res = 0;
	for (int i = 0; i < size; ++i)
	{
		if (digits[i] < arrN[index])
			res += pow(size, index);
		else
		{
			if (digits[i] == arrN[index])
				res += dfs(digits, size, arrN, index - 1);
			break;
		}
	}
	return res;
}

int atMostNGivenDigitSet(char **D, int DSize, int N)
{
	int digits[DSize];
	for (int i = 0; i < DSize; ++i)
		digits[i] = D[i][0] - '0';
	int arrN[10], n = -1;
	for (; N != 0; N /= 10)
		arrN[++n] = N % 10;
	int res = 0;
	if (n != 0)
	{
		if (DSize == 1)
			res = n;
		else
			res = ((long)pow(DSize, n + 1) - DSize) / (DSize - 1);
	}
	return res + dfs(digits, DSize, arrN, n);
}
