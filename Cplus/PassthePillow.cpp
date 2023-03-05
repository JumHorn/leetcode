class Solution
{
public:
	int passThePillow(int n, int time)
	{
		int p = time / (n - 1), q = time % (n - 1);
		if (q == 0)
			return p % 2 == 1 ? n : 1;
		return p % 2 == 1 ? (n - q) : (1 + q);
	}
};