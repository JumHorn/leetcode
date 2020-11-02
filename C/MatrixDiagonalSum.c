
int diagonalSum(int** mat, int matSize, int* matColSize)
{
	int res = 0;
	for (int i = 0; i < matSize; ++i)
		res += mat[i][i] + mat[matSize - i - 1][i];
	if (matSize % 2 == 1)
		res -= mat[matSize / 2][matSize / 2];
	return res;
}
