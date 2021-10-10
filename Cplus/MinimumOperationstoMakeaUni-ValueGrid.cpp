#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<vector<int>> &grid, int x)
	{
		vector<int> v;
		for (auto &row : grid)
		{
			for (auto n : row)
				v.push_back(n);
		}
		int remaider = v[0] % x;
		for (auto n : v)
		{
			if (n % x != remaider)
				return -1;
		}
		sort(v.begin(), v.end());
		int N = v.size(), res = 0, mid = v[N / 2];
		for (int i = 0, j = N - 1; i < j; ++i, --j)
			res += (v[j] - v[i]) / x;
		return res;
	}
};