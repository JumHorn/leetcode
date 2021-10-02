#include <algorithm>
#include <vector>
using namespace std;

/*
方案一: 动态规划优化
the original dp function
dp[i]=max{prices[i]-prices[j]-fee+dp[j-1]} (0<j<i)

optimization
dp[i]=max{prices[i]-fee+(dp[j-1]-prices[j])} (0=<j<i)
dp1[j]=max{dp[j-1]-prices[j]} record max dp[j-1]-prices[j]
dp[i]=max(dp[i-1],dp1[i-1]+prices[i]-fee)

方案二: 另外一种动态规划
buy	进行买入操作的最大收益
sell进行卖出操作的最大收益
*/

class Solution
{
public:
	int maxProfit(vector<int> &prices, int fee)
	{
		int buy = -prices.front(), sell = 0;
		for (int i = 1; i < (int)prices.size(); ++i)
		{
			sell = max(sell, buy + prices[i] - fee);
			buy = max(buy, sell - prices[i]);
		}
		return sell;
	}
};