#include <algorithm>
#include <vector>
using namespace std;

/*
方案一: 动态规划优化
the original dp
dp[i][k] max profit with i prices in k transaction
dp[i][k]=max{prices[i]-prices[j]+dp[j-1][k-1]} (0<j<i)
dp[i][k]=max{prices[i]+(dp[j-1][k-1]-prices[j])} (0<j<i)

optimization
inner loop k is constant
dp1[j]=max{dp[j-1][k-1]-prices[j]}
dp[i][k]=max{prices[i]+dp1[j]}

方案二: 另外一种动态规划
buy1	只进行过一次买操作
sell1	进行了一次买操作和一次卖操作，即完成了一笔交易
buy2	在完成了一笔交易的前提下，进行了第二次买操作
sell2	完成了全部两笔交易
...
...
buyn	在完成了n笔交易的前提下，进行了第n次买操作
selln	完成了全部n笔交易
*/

class Solution
{
public:
	int maxProfit(int k, vector<int> &prices)
	{
		if (prices.empty() || k == 0)
			return 0;
		int N = prices.size();
		if (k > N)
		{
			int res = 0;
			for (int i = 1; i < N; ++i)
				res += max(prices[i] - prices[i - 1], 0);
			return res;
		}
		vector<int> hold(k), sold(k);
		for (int i = 0; i < k; ++i)
			hold[i] = -prices[0];
		for (auto p : prices)
		{
			hold[0] = max(-p, hold[0]);
			sold[0] = max(hold[0] + p, sold[0]);
			for (int j = 1; j < k; ++j)
			{
				hold[j] = max(sold[j - 1] - p, hold[j]);
				sold[j] = max(hold[j] + p, sold[j]);
			}
		}
		return sold[k - 1];
	}
};