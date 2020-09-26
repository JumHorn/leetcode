#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findRightInterval(vector<vector<int>> &intervals)
	{
		map<int, int> hash;
		vector<int> res;
		int n = intervals.size();
		for (int i = 0; i < n; ++i)
			hash[intervals[i][0]] = i;
		for (auto interval : intervals)
		{
			auto iter = hash.lower_bound(interval[1]);
			if (iter == hash.end())
				res.push_back(-1);
			else
				res.push_back(iter->second);
		}
		return res;
	}
};