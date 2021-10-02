#include <vector>
using namespace std;

/*
方案一: 动态规划优化
the original dp function
dp[i]=max{prices[i]-prices[j]-fee+dp[j-2]} (1<j<i)

optimization
dp[i]=max{prices[i]-fee+(dp[j-2]-prices[j])} (1<j<i)
dp1[j]=max{dp[j-2]-prices[j]} record max dp[j-2]-prices[j]
dp[i]=max(dp[i-1],dp1[i-1]+prices[i]-fee)

方案二: 另外一种动态规划
buy_pre 之前所有操作最后一次买入的最大收益
sel_pre 之前所有操作最后一次卖出的最大收益
buy		再次进行买入操作的最大收益
sell	再次进行卖出操作的最大收益
*/

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int N = prices.size();
		if (N < 2)
			return 0;
		int sell = max(0, prices[1] - prices[0]), sell_pre0 = 0, sell_pre1 = 0;
		int buy = max(-prices[0], -prices[1]);
		for (int i = 2; i < N; ++i)
		{
			sell_pre1 = sell_pre0;
			sell_pre0 = sell;
			sell = max(sell, buy + prices[i]);
			buy = max(buy, sell_pre1 - prices[i]);
		}
		return sell;
	}
};