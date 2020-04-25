#include <vector>
#include <algorithm>
using namespace std;

/*
buy[i]=sold[i-1]-price[i]
sold[i]=buy[i-1]+price[i]-fee
*/

class Solution
{
public:
	int maxProfit(vector<int> &prices, int fee)
	{
		int buy = -prices.front(), sold = 0;
		for (int i = 1; i < (int)prices.size(); i++)
		{
			sold = max(sold, buy + prices[i] - fee);
			buy = max(buy, sold - prices[i]);
		}
		return sold;
	}
};