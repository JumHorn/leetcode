#include <vector>
using namespace std;

/*
dp[m][k] m step and k eggs can reach highest
*/

class Solution
{
public:
	int twoEggDrop(int n)
	{
		const int K = 2;
		vector<vector<int>> dp(n + 1, vector<int>(K + 1));
		int m = 0;
		for (; dp[m][K] < n; ++m)
		{
			for (int j = 1; j <= K; ++j)
				dp[m + 1][j] = dp[m][j - 1] + dp[m][j] + 1;
		}
		return m;
	}
};