

int countTriplets(int* A, int ASize)
{
	int count[1 << 16] = {0};
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = 0; j < ASize; ++j)
			++count[A[i] & A[j]];
	}
	int res = 0;
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = 0; j < 1 << 16; ++j)
		{
			if ((j & A[i]) == 0)
				res += count[j];
		}
	}
	return res;
}
