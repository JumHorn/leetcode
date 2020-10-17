
int smallestRepunitDivByK(int K)
{
	int remainder = 0;
	for (int i = 1; i <= K; ++i)
	{
		remainder = (remainder * 10 + 1) % K;
		if (remainder == 0)
			return i;
	}
	return -1;
}
