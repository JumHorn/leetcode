#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int deleteGreatestValue(vector<vector<int>> &grid)
	{
		for (auto &v : grid)
			sort(v.begin(), v.end());
		int N = grid[0].size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			int maxval = 0;
			for (auto &v : grid)
				maxval = max(maxval, v[i]);
			res += maxval;
		}
		return res;
	}
};