#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSum(vector<int> &nums)
	{
		vector<pair<int, int>> v; //{max digits,val}
		for (auto n : nums)
			v.push_back({maxDigit(n), n});
		sort(v.begin(), v.end());
		int res = -1, N = v.size();
		for (int i = N - 1, j = N - 2; j >= 0; i = j--)
		{
			if (v[i].first == v[j].first)
				res = max(res, v[i].second + v[j].second);
		}
		return res;
	}

	int maxDigit(int n)
	{
		int res = 0;
		for (; n != 0; n /= 10)
			res = max(res, n % 10);
		return res;
	}
};