
int dfs(int* digits, int size, int N, long val)
{
	if (val > N)
		return 0;
	int res = 1;
	for (int i = 0; i < size; ++i)
		res += dfs(digits, size, N, val * 10 + digits[i]);
	return res;
}

int atMostNGivenDigitSet(char** D, int DSize, int N)
{
	int digits[DSize];
	for (int i = 0; i < DSize; ++i)
		digits[i] = D[i][0] - '0';
	return dfs(digits, DSize, N, 0) - 1;  //0 not include
}
