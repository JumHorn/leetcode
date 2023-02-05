#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minCost(vector<int> &basket1, vector<int> &basket2)
	{
		int N = basket1.size(), minval = INT_MAX;
		unordered_map<int, int> m;
		for (int i = 0; i < N; ++i)
		{
			++m[basket1[i]];
			--m[basket2[i]];
		}
		vector<int> v;
		long long res = 0;
		for (auto [val, count] : m)
		{
			if (count % 2 != 0)
				return -1;
			minval = min(minval, val);
			v.insert(v.end(), abs(count / 2), val);
		}
		// 排序使得中间的数在正确位置,比中间小的数在左侧,必中间大的数在右侧
		nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
		for (int i = 0; i < v.size() / 2; ++i)
			res += min(v[i], minval * 2);
		return res;
	}
};