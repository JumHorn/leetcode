
int countTriplets(int *A, int ASize)
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
		int mask = (((1 << 16) - 1) & (~A[i]));
		res += count[0];
		for (int j = mask; j > 0; j = ((j - 1) & mask))
			res += count[j];
	}
	return res;
}