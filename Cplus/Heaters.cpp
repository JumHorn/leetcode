#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int findRadius(vector<int> &houses, vector<int> &heaters)
	{
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int res = 0;
		for (int i = 0, j = 0; i < (int)houses.size(); ++i)
		{
			while (j < (int)heaters.size() && houses[i] > heaters[j])
				++j;
			int radius = INT_MAX;
			if (j < (int)heaters.size())
				radius = min(radius, heaters[j] - houses[i]);
			if (j > 0)
				radius = min(radius, houses[i] - heaters[j - 1]);
			res = max(res, radius);
		}
		return res;
	}
};