#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res;
		for (int i = 0, maxright = INT_MIN; i < (int)intervals.size(); ++i)
		{
			if (intervals[i][0] > maxright)
				res.push_back(intervals[i]);
			if (intervals[i][1] > maxright)
				maxright = res.back()[1] = intervals[i][1];
		}
		return res;
	}
};