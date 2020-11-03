#define max(a, b) (((a) > (b)) ? (a) : (b))

int shipWithinDays(int *weights, int weightsSize, int D)
{
	int lo = 0, hi = 0;
	for (int i = 0; i < weightsSize; ++i)
	{
		lo = max(lo, weights[i]);
		hi += weights[i];
	}
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo, cap = 0, day = 1;
		for (int i = 0; i < weightsSize && day <= D; ++i)
		{
			if (cap + weights[i] > mi)
			{
				cap = weights[i];
				day++;
			}
			else
				cap += weights[i];
		}
		if (day > D)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}