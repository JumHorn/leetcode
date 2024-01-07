#include <vector>
using namespace std;

class Solution
{
public:
	int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
	{
		int d = 0, area = 0;
		for (auto &v : dimensions)
		{
			int l = v[0], w = v[1];
			int d1 = l * l + w * w;
			if (d1 > d)
			{
				d = d1;
				area = l * w;
			}
			else if (d1 == d)
				area = max(area, l * w);
		}
		return area;
	}
};