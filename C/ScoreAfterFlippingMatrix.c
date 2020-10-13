
#define max(a, b) (((a) > (b)) ? (a) : (b))

int matrixScore(int **A, int ASize, int *AColSize)
{
	int res = 0, N = *AColSize;
	for (int j = N - 1; j >= 0; --j)
	{
		int one = 0;
		for (int i = 0; i < ASize; ++i)
			one += A[i][j] ^ A[i][0];
		res += max(one, ASize - one) * (1 << (N - j - 1));
	}
	return res;
}