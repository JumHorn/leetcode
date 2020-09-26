
int countArithmeticSlices(int slicelen)
{
	return (slicelen - 1) * (slicelen - 2) / 2;
}

int numberOfArithmeticSlices(int* A, int ASize)
{
	int res = 0;
	for (int i = 1, j = 0; i < ASize; ++i)
	{
		if (i < ASize - 1 && A[i] - A[i - 1] != A[i + 1] - A[i])
		{
			res += countArithmeticSlices(i - j + 1);
			j = i;
		}
		if (i == ASize - 1 && i - j + 1 >= 3)
			res += countArithmeticSlices(i - j + 1);
	}
	return res;
}
