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
*/

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.empty())
			return 0;
		int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
		for (auto p : prices)
		{
			buy1 = max(buy1, -p);
			sell1 = max(sell1, buy1 + p);

			buy2 = max(buy2, sell1 - p);
			sell2 = max(sell2, buy2 + p);
		}
		return sell2;
	}
};