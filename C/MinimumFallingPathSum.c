
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minFallingPathSum(int** A, int ASize, int* AColSize)
{
	if (*AColSize == 1)
	{
		int res = 0;
		for (int i = 0; i < ASize; i++)
			res += A[i][0];
		return res;
	}
	for (int i = 1; i < ASize; i++)
	{
		for (int j = 1; j < *AColSize - 1; j++)
			A[i][j] += min(A[i - 1][j], min(A[i - 1][j - 1], A[i - 1][j + 1]));
		A[i][0] += min(A[i - 1][0], A[i - 1][1]);
		A[i][*AColSize - 1] += min(A[i - 1][*AColSize - 1], A[i - 1][*AColSize - 2]);
	}
	int res = 10000;
	for (int i = 0; i < *AColSize; i++)
		if (A[ASize - 1][i] < res)
			res = A[ASize - 1][i];
	return res;
}

