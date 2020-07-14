#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxArea(vector<int> &height)
	{
		int res = 0;
		for (int i = 0, j = height.size() - 1; i < j;)
		{
			res = max(res, (j - i) * min(height[i], height[j]));
			height[i] < height[j] ? ++i : --j;
		}
		return res;
	}
};