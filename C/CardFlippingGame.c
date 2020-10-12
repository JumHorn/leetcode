
#define min(a, b) (((a) < (b)) ? (a) : (b))

int flipgame(int* fronts, int frontsSize, int* backs, int backsSize)
{
	int same[2001] = {0};
	for (int i = 0; i < frontsSize; ++i)
	{
		if (fronts[i] == backs[i])
			same[fronts[i]] = 1;
	}
	int res = 2001;
	for (int i = 0; i < frontsSize; ++i)
	{
		if (same[fronts[i]] != 1)
			res = min(res, fronts[i]);
		if (same[backs[i]] != 1)
			res = min(res, backs[i]);
	}
	return res % 2001;
}
