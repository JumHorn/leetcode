
int numEquivDominoPairs(int **dominoes, int dominoesSize, int *dominoesColSize)
{
	int count[10][10] = {0};
	for (int i = 0; i < dominoesSize; ++i)
	{
		if (dominoes[i][0] <= dominoes[i][1])
			++count[dominoes[i][0]][dominoes[i][1]];
		else
			++count[dominoes[i][1]][dominoes[i][0]];
	}
	int res = 0;
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = i; j <= 9; ++j)
			res += count[i][j] * (count[i][j] - 1) / 2;
	}
	return res;
}