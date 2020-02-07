
int recursive(int seen, int index, int N)
{
	if (index == N)
		return 1;
	int res = 0, old_seen = seen;
	for (int i = 0; i < N; i++)
	{
		seen = old_seen;
		if ((seen & (1 << i)) == 0)
		{
			if ((i + 1) % (index + 1) == 0 || (index + 1) % (i + 1) == 0)
			{
				seen = (seen | (1 << i));
				res += recursive(seen, index + 1, N);
			}
		}
	}
	return res;
}

int countArrangement(int N)
{
	return recursive(0, 0, N);
}