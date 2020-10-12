#include <vector>
using namespace std;

class Solution
{
public:
	double new21Game(int N, int K, int W)
	{
		if (K == 0 || N >= K + W)
			return 1.0;
		vector<double> dp(K, -1);
		return memdp(N, K, W, 0, dp);
	}

	double memdp(int N, int K, int W, int point, vector<double> &dp)
	{
		if (point >= K)
			return point <= N ? 1.0 : 0.0;
		if (dp[point] >= 0.0)
			return dp[point];
		double res = 0.0;
		for (int i = 1; i <= W; ++i)
			res += 1.0 / W * memdp(N, K, W, point + i, dp);
		return dp[point] = res;
	}
};