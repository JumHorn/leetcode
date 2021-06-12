#include <vector>
using namespace std;

class Solution
{
public:
	bool isCovered(vector<vector<int>> &ranges, int left, int right)
	{
		for (int i = left; i <= right; ++i)
		{
			bool flag = false;
			for (auto &v : ranges)
			{
				if (i >= v[0] && i <= v[1])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
				return false;
		}
		return true;
	}
};