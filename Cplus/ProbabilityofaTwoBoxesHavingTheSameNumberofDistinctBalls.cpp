#include <numeric>
#include <vector>
using namespace std;

/*
dp[m][k] saves number of cases with equal number of colors in both boxes and k balls in the first box
and dp[m-x][k] saves number of cases where first box has x less colors, and dp[m+x][k] saves number of cases where first box has x more colors
*/

class Solution
{
public:
	double getProbability(vector<int> &balls)
	{
		int N = balls.size();
		int S = accumulate(balls.begin(), balls.end(), 0);

		//combination table
		vector<vector<double>> combination(S + 1, vector<double>(S / 2 + 1));
		combination[0][0] = 1;
		for (int i = 1; i < S + 1; ++i)
		{
			combination[i][0] = 1;
			for (int j = 1; j < S / 2 + 1; ++j)
				combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];
		}

		//dp
		vector<vector<double>> dp(2 * N + 1, vector<double>(S / 2 + 1));
		dp[N][0] = 1; //dp begins from this point
		int sum = 0;
		for (auto b : balls) //different color balls
		{
			sum += b;
			vector<vector<double>> next_dp(2 * N + 1, vector<double>(S / 2 + 1));
			for (int i = 0; i <= b; ++i) //distribute balls to each box
			{
				for (int j = 0; j < 2 * N + 1; ++j) //color diff
				{
					for (int k = 0; k < S / 2 + 1; ++k) // first box ball count
					{
						if (dp[j][k] == 0)
							continue;
						int ballCount = k + i;
						int other = sum - ballCount;
						if (ballCount <= S / 2 && other <= S / 2)
						{
							int colorDiff = (i == 0) ? j - 1 : (i == b) ? j + 1 : j;
							next_dp[colorDiff][ballCount] += dp[j][k] * combination[b][i];
						}
					}
				}
			}
			dp = next_dp;
		}
		return dp[N][S / 2] / combination[S][S / 2];
	}
};