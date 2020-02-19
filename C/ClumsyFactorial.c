
int recursive(int N, int flag, int pre, int res)
{
	if (N == 0)
		return res;
	flag %= 4;
	if (flag == 0) //*
		res = recursive(N - 1, flag + 1, pre * N, res - pre + pre * N);
	else if (flag == 1) // /
		res = recursive(N - 1, flag + 1, pre / N, res - pre + pre / N);
	else if (flag == 2) // +
		res = recursive(N - 1, flag + 1, N, res + N);
	else // -
		res = recursive(N - 1, flag + 1, -N, res - N);
	return res;
}

int clumsy(int N)
{
	return recursive(N - 1, 0, N, N);
}

int main()
{
	clumsy(5);
	return 0;
}