#include <algorithm>
#include <vector>
using namespace std;

/*
max(h1, h2) + (r - l - abs(h1 - h2)) / 2
equals to
(r - l + h1 + h2) / 2
*/

class Solution
{
public:
	int maxBuilding(int n, vector<vector<int>> &restrictions)
	{
		restrictions.push_back({1, 0});
		restrictions.push_back({n, n - 1});
		sort(restrictions.begin(), restrictions.end());
		int N = restrictions.size();
		for (int i = 1; i < N; ++i)
			restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
		for (int i = N - 2; i >= 0; --i)
			restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);

		int res = 0;
		for (int i = 1; i < N; ++i)
		{
			int l = restrictions[i - 1][0], r = restrictions[i][0], h1 = restrictions[i - 1][1], h2 = restrictions[i][1];
			res = max(res, (r - l + h1 + h2) / 2);
		}
		return res;
	}
};