#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxIncreasingGroups(vector<int> &usageLimits)
	{
		sort(usageLimits.begin(), usageLimits.end());
		long long sum = 0, g = 0; // group
		for (auto n : usageLimits)
		{
			sum += n;
			if (sum >= (g + 1) * (g + 2) / 2)
				++g;
		}
		return g;
	}
};