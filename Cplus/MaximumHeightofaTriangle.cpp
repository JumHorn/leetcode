class Solution
{
public:
	int maxHeightOfTriangle(int red, int blue)
	{
		int res = 0, odd = 1, even = 0;
		while ((red >= odd && blue >= even) || (red >= even && blue >= odd))
		{
			++res;
			if (res % 2 == 1)
				even += res + 1;
			else
				odd += res + 1;
		}
		return res;
	}
};