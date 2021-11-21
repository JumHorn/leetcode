#include <vector>
using namespace std;

class Solution
{
public:
	int maxDistance(vector<int> &colors)
	{
		int c1 = colors[0], index1 = 0, c2 = -1, index2 = -1, N = colors.size(), res = 0;
		if (colors[1] != c1)
		{
			c2 = colors[1];
			index2 = 1;
			res = 1;
		}
		for (int i = 2; i < N; ++i)
		{
			if (c2 == -1 && colors[i] != c1)
			{
				c2 = colors[i];
				index2 = i;
			}
			if (colors[i] != c1)
				res = max(res, i);
			if (c2 != -1 && colors[i] != c2)
				res = max(res, i - index2);
		}
		return res;
	}
};