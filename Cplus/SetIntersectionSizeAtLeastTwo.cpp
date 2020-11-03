#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int intersectionSizeTwo(vector<vector<int>> &intervals)
	{
		sort(intervals.begin(), intervals.end(), *this);
		int a = intervals[0][1] - 1, b = a + 1, res = 2;
		for (int i = 1; i < (int)intervals.size(); ++i)
		{
			if (intervals[i][0] > a)
			{
				if (intervals[i][0] > b)
				{
					++res;
					a = intervals[i][1] - 1;
				}
				else
					a = b;
				b = intervals[i][1];
				++res;
			}
		}
		return res;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		if (lhs[1] != rhs[1])
			return lhs[1] < rhs[1];
		return lhs[0] > rhs[0];
	}
};