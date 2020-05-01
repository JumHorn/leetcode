#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*
the original dp
dp[i][k] max profit with i prices in k transaction
dp[i][k]=max{prices[i]-prices[j]+dp[j-1][k-1]} (0<j<i)
dp[i][k]=max{prices[i]+(dp[j-1][k-1]-prices[j])} (0<j<i)

optimization
inner loop k is constant
dp1[j]=max{dp[j-1][k-1]-prices[j]}
dp[i][k]=max{prices[i]+dp1[j]}
*/

class Solution
{
public:
	int maxProfit(int k, vector<int> &prices)
	{
		if (prices.empty() || k == 0)
			return 0;
		if (k > (int)prices.size() / 2)
		{
			int res = 0;
			for (int i = 1; i < (int)prices.size(); i++)
				res += max(prices[i] - prices[i - 1], 0);
			return res;
		}
		int hold[k], sold[k];
		memset(sold, 0, sizeof(sold));
		for (int i = 0; i < k; i++)
			hold[i] = -prices[0];
		for (int i = 0; i < (int)prices.size(); i++)
		{
			hold[0] = max(-prices[i], hold[0]);
			sold[0] = max(hold[0] + prices[i], sold[0]);
			for (int j = 1; j < k; j++)
			{
				hold[j] = max(sold[j - 1] - prices[i], hold[j]);
				sold[j] = max(hold[j] + prices[i], sold[j]);
			}
		}
		return sold[k - 1];
	}
};