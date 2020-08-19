#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxDistance(vector<int>& position, int m)
	{
		sort(position.begin(), position.end());
		int lo = 0, hi = (position.back() - position.front()) / (m - 1) + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (maxPlaceCount(position, mi) >= m)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	int maxPlaceCount(vector<int>& position, int interval)
	{
		int res = 1, distance = 0;
		for (int i = 1; i < (int)position.size(); ++i)
		{
			distance += position[i] - position[i - 1];
			if (distance >= interval)
			{
				distance = 0;
				++res;
			}
		}
		return res;
	}
};
