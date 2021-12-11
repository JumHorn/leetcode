#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maxSubsequence(vector<int> &nums, int k)
	{
		vector<int> res;
		vector<int> v = nums;
		sort(v.begin(), v.end(), greater<int>());
		unordered_map<int, int> m; //{value,count}
		for (int i = 0; i < k; ++i)
			++m[v[i]];
		for (auto n : nums)
		{
			if (--m[n] >= 0)
				res.push_back(n);
		}
		return res;
	}
};