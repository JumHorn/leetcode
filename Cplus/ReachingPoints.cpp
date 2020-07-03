class Solution
{
public:
	bool reachingPoints(int sx, int sy, int tx, int ty)
	{
		while (sx < tx && sy < ty)
		{
			if (tx > ty)
				tx %= ty;
			else
				ty %= tx;
		}
		return (sx == tx && sy == ty) || (sx == tx && ty >= sy && 0 == (ty - sy) % tx) || (sy == ty && tx >= sx && 0 == (tx - sx) % ty);
	}
};