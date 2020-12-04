#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
	{
		vector<vector<int>> res;
		int N = intervals.size();
		for (int i = 0; i < N; ++i)
		{
			if (i == N || newInterval[1] < intervals[i][0])
			{
				res.push_back(newInterval);
				for (; i < N; ++i)
					res.push_back(intervals[i]);
			}
			else
			{
				if (newInterval[0] > intervals[i][1])
					res.push_back(intervals[i]);
				else
				{
					newInterval[0] = min(newInterval[0], intervals[i][0]);
					newInterval[1] = max(newInterval[1], intervals[i][1]);
				}
			}
		}
		return res;
	}
};