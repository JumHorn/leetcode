#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
	{
		vector<vector<int>> index(101); //index
		int N = nums.size();
		for (int i = 0; i < N; ++i)
			index[nums[i]].push_back(i);
		vector<int> res;
		for (auto &q : queries)
		{
			int l = -1, r = 1, val = INT_MAX;
			for (; r <= 100; ++r)
			{
				if (valueInRange(index[r], q[0], q[1]))
				{
					if (l != -1)
						val = min(val, r - l);
					l = r;
				}
			}
			res.push_back(val == INT_MAX ? -1 : val);
		}
		return res;
	}

	bool valueInRange(vector<int> &v, int left, int right)
	{
		auto iter = lower_bound(v.begin(), v.end(), left);
		if (iter == v.end())
			return false;
		return *iter <= right;
	}
};