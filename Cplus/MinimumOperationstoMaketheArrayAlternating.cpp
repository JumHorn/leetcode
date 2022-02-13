#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumOperations(vector<int> &nums)
	{
		int N = nums.size(), res = N, MAXN = 1e5 + 1;
		if (N <= 1)
			return 0;
		vector<int> odd(MAXN), even(MAXN); //{val,count}
		for (int i = 0; i < N; ++i)
		{
			if (i % 2 == 0)
				++even[nums[i]];
			else
				++odd[nums[i]];
		}
		vector<pair<int, int>> v0, v1; //{count,val}
		for (int i = 0; i < MAXN; ++i)
		{
			if (even[i] != 0)
				v0.push_back({even[i], i});
		}
		for (int i = 0; i < MAXN; ++i)
		{
			if (odd[i] != 0)
				v1.push_back({odd[i], i});
		}
		sort(v0.begin(), v0.end(), greater<pair<int, int>>());
		sort(v1.begin(), v1.end(), greater<pair<int, int>>());
		for (int i = 0; i < (int)v0.size() && i < 2; ++i)
		{
			for (int j = 0; j < (int)v1.size(); ++j)
			{
				if (v0[i].second != v1[j].second)
				{
					res = min(res, N - v0[i].first - v1[j].first);
					break;
				}
				else
				{
					res = min(res, N - v0[i].first);
					res = min(res, N - v1[j].first);
				}
			}
		}

		return res;
	}
};