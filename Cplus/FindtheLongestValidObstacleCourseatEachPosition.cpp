#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
	{
		int N = obstacles.size();
		vector<int> res, LIS;
		for (auto n : obstacles)
		{
			int lo = 0, hi = LIS.size();
			while (lo < hi)
			{
				int mi = (hi - lo) / 2 + lo;
				if (LIS[mi] <= n)
					lo = mi + 1;
				else
					hi = mi;
			}
			if (lo == LIS.size())
				LIS.push_back(n);
			else
				LIS[lo] = n;
			res.push_back(lo + 1);
		}
		return res;
	}
};