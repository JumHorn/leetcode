#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDifficulty(vector<int> &jobDifficulty, int d)
	{
		int len = jobDifficulty.size();
		if (len < d)
			return -1;
		vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(d + 1)));
		for (int i = 0; i < len; i++)
			dp[i][i][1] = jobDifficulty[i];
		for (int i = 1; i < len; i++)
		{
			for (int j = 0; j + i < len; j++)
				dp[j][j + i][1] = max(dp[j][j][1], dp[j + 1][j + i][1]);
		}
		for (int l = 1; l < len; l++)
		{
			for (int i = 0; i + l < len; i++)
			{
				int j = i + l;
				for (int k = 2; k <= min(d, l + 1); k++)
				{
					dp[i][j][k] = INT_MAX;
					for (int m = i; m < j; m++)
					{
						for (int n = max(1, k - j + m); n <= min(k - 1, m - i + 1); n++)
						{
							dp[i][j][k] = min(dp[i][j][k], dp[i][m][n] + dp[m + 1][j][k - n]);
						}
					}
				}
			}
		}
		return dp[0][len - 1][d];
	}
};

int main()
{
	vector<int> v = {11, 111, 22, 222, 33, 333, 44, 444};
	Solution sol;
	sol.minDifficulty(v, 6);
	return 0;
}