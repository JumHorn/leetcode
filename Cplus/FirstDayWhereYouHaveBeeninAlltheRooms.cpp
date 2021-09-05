#include <vector>
using namespace std;

class Solution
{
public:
	int firstDayBeenInAllRooms(vector<int> &nextVisit)
	{
		int N = nextVisit.size();
		vector<int> dp(N); //表示访问到i的总天数
		for (int i = 0; i < N - 1; ++i)
		{
			int d = (dp[i] - dp[nextVisit[i]] + 2 + MOD) % MOD; //访问当前i所用天数
			dp[i + 1] = (dp[i] + d) % MOD;
		}
		return dp[N - 1];
	}

private:
	static const int MOD = 1e9 + 7;
};