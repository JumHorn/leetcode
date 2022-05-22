#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
	{
		vector<int> v;
		int N = rocks.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			int diff = capacity[i] - rocks[i];
			if (diff == 0)
				++res;
			else
				v.push_back(diff);
		}
		sort(v.begin(), v.end());
		for (auto n : v)
		{
			if (additionalRocks < n)
				break;
			++res;
			additionalRocks -= n;
		}
		return res;
	}
};