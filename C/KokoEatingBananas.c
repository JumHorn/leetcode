
int timeToEatAll(int* piles, int pilesSize, int k)
{
	int hour = 0;
	for (int i = 0; i < pilesSize; ++i)
		hour += (piles[i] - 1) / k + 1;
	return hour;
}

int minEatingSpeed(int* piles, int pilesSize, int H)
{
	int lo = 1, hi = 1e9;
	while (lo < hi)
	{
		int mi = lo + (hi - lo) / 2;
		if (timeToEatAll(piles, pilesSize, mi) > H)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}
