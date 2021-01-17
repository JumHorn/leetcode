#include <vector>
using namespace std;

class Solution
{
public:
	int countGoodRectangles(vector<vector<int>> &rectangles)
	{
		int maxLen = 0, res = 0;
		for (auto &v : rectangles)
		{
			int side = min(v[0], v[1]);
			if (side > maxLen)
			{
				maxLen = side;
				res = 1;
			}
			else if (side == maxLen)
				++res;
		}
		return res;
	}
};