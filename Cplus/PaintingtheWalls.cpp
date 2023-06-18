#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int paintWalls(vector<int> &cost, vector<int> &time)
	{
		int N = cost.size();
		vector<unordered_map<int, int>> dp(N);
		function<int(int, int)> memdp = [&](int index, int t)
		{
			if (t > index)
				return 0;
			if (index < 0)
				return INT_MAX / 2;
			auto it = dp[index].find(t);
			if (it != dp[index].end())
				return it->second;
			return dp[index][t] = min(memdp(index - 1, t + time[index]) + cost[index], memdp(index - 1, t - 1));
		};
		return memdp(N - 1, 0);
	}
};