#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int memdp(vector<int> &locations, int start, int finish, int fuel, vector<vector<int>> dp)
	{
		if (fuel == 0)
			return start == finish ? 1 : 0;
		int res = start == finish ? 1 : 0;
		if (dp[start][fuel] != -1)
			return dp[start][fuel];
		for (int i = 0; i < (int)locations.size(); ++i)
		{
			if (i != start)
			{
				int val = abs(locations[i] - locations[start]);
				if (fuel >= val)
					res = (res + memdp(locations, i, finish, fuel - val, dp)) % MOD;
			}
		}
		return dp[start][fuel] = res;
	}

	int countRoutes(vector<int> &locations, int start, int finish, int fuel)
	{
		int n = locations.size();
		vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
		return memdp(locations, start, finish, fuel, dp);
	}

private:
	static const int MOD = 1e9 + 7;
};