
int minDeletionSize(char **A, int ASize)
{
	int res = 0;
	for (int i = 0, j = 0; A[0][j]; ++j)
	{
		for (i = 1; i < ASize; ++i)
		{
			if (A[i - 1][j] > A[i][j])
				break;
		}
		if (i != ASize)
			++res;
	}
	return res;
}