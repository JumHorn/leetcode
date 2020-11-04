
int count(int* bloomDay, int bloomDaySize, int k, int day)
{
	int res = 0, flowers = 0;
	for (int i = 0; i < bloomDaySize; ++i)
	{
		if (bloomDay[i] <= day)
		{
			if (++flowers == k)
			{
				++res;
				flowers = 0;
			}
		}
		else
			flowers = 0;
	}
	return res;
}

int minDays(int* bloomDay, int bloomDaySize, int m, int k)
{
	if (m * k > bloomDaySize)
		return -1;
	int lo = bloomDay[0], hi = bloomDay[0];
	for (int i = 1; i < bloomDaySize; ++i)
	{
		if (bloomDay[i] < lo)
			lo = bloomDay[i];
		else if (bloomDay[i] > hi)
			hi = bloomDay[i];
	}
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (count(bloomDay, bloomDaySize, k, mi) < m)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}
