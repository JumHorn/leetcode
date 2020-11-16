class Solution
{
public:
	bool reachingPoints(int sx, int sy, int tx, int ty)
	{
		while (sx < tx && sy < ty)
			tx > ty ? (tx %= ty) : (ty %= tx);
		return (sx == tx && sy == ty) ||
			   (sx == tx && ty >= sy && (ty - sy) % tx == 0) ||
			   (sy == ty && tx >= sx && (tx - sx) % ty == 0);
	}
};