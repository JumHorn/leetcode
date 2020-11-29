#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

/*
按位与之值最多只有20种不同的值
*/

class Solution
{
public:
	int closestToTarget(vector<int> &arr, int target)
	{
		set<int> s, next_s;
		int res = target + 1e9, N = arr.size();
		for (int i = 0; i < N; ++i)
		{
			next_s.clear();
			next_s.insert(arr[i]);
			for (auto n : s)
				next_s.insert(n & arr[i]);
			auto iter = next_s.lower_bound(target);
			if (iter != next_s.end())
				res = min(res, *iter - target);
			if (iter != next_s.begin())
			{
				--iter;
				res = min(res, target - *iter);
			}
			swap(s, next_s);
		}
		return res;
	}
};