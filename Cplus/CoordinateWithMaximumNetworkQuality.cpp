#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> bestCoordinate(vector<vector<int>> &towers, int radius)
	{
		vector<int> res;
		int maxquality = -1;
		for (int i = 0; i <= 50; ++i)
		{
			for (int j = 0; j <= 50; ++j)
			{
				int quality = getPostionQuality(towers, i, j, radius);
				if (quality > maxquality)
				{
					maxquality = quality;
					res = {i, j};
				}
			}
		}
		return res;
	}

	int getPostionQuality(vector<vector<int>> &tower, int x, int y, int radius)
	{
		int res = 0;
		for (auto &p : tower)
		{
			double d = sqrt((p[0] - x) * (p[0] - x) + (p[1] - y) * (p[1] - y));
			if (d <= radius)
				res += p[2] / (1 + d);
		}
		return res;
	}
};