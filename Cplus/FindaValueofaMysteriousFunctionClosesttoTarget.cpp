#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int closestToTarget(vector<int>& arr, int target)
	{
		set<int> s;
		int res = target + 1e9, N = arr.size();
		for (int i = 0; i < N; i++)
		{
			set<int> s1;
			s1.insert(arr[i]);
			for (auto n : s)
				s1.insert(n & arr[i]);
			auto iter = s1.lower_bound(target);
			if (iter != s1.end())
				res = min(res, *iter - target);
			if (iter != s1.begin())
			{
				--iter;
				res = min(res, target - *iter);
			}
			swap(s, s1);
		}
		return res;
	}
};
