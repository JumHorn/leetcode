
class Solution
{
public:
	int minFlips(int a, int b, int c)
	{
		int bit = 1, res = 0, d = (a | b);
		if (d == c)
			return 0;
		while (bit <= d || bit <= c)
		{
			if ((c & bit) != (d & bit))
			{
				if (c & bit)  //1
				{
					++res;
				}
				else  //0
				{
					if (a & bit)
						++res;
					if (b & bit)
						++res;
				}
			}
			bit <<= 1;
		}
		return res;
	}
};
