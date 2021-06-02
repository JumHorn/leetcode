
int atMostK(int *A, int ASize, int K)
{
	int window[20001] = {0}, res = 0;
	for (int i = 0, j = 0; i < ASize; ++i)
	{
		if (window[A[i]] == 0)
			--K;
		++window[A[i]];
		for (; K < 0; ++j)
		{
			if (--window[A[j]] == 0)
				++K;
		}
		res += i - j + 1;
	}
	return res;
}

int subarraysWithKDistinct(int *A, int ASize, int K)
{
	return atMostK(A, ASize, K) - atMostK(A, ASize, K - 1);
}