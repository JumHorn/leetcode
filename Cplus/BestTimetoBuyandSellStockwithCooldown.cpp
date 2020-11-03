#include <vector>
using namespace std;

/*
the original dp function
dp[i]=max{prices[i]-prices[j]-fee+dp[j-2]} (1<j<i)

optimization
dp[i]=max{prices[i]-fee+(dp[j-2]-prices[j])} (1<j<i)
dp1[j]=max{dp[j-2]-prices[j]} record max dp[j-2]-prices[j]
dp[i]=max(dp[i-1],dp1[i-1]+prices[i]-fee)
*/

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int n = prices.size();
		if (n < 2)
			return 0;
		int sell = max(0, prices[1] - prices[0]), sell_pre0 = 0, sell_pre1 = 0;
		int buy = max(-prices[0], -prices[1]);
		for (int i = 2; i < n; ++i)
		{
			sell_pre1 = sell_pre0;
			sell_pre0 = sell;
			sell = max(sell, buy + prices[i]);
			buy = max(buy, sell_pre1 - prices[i]);
		}
		return sell;
	}
};