#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int n = prices.size();
		if (prices.size() < 2)
			return 0;
		vector<int> hold(n), sold(n);
		hold[0] = -prices[0];
		sold[0] = 0;
		hold[1] = max(sold[0] - prices[1], hold[0]);
		sold[1] = max(0, prices[1] - prices[0]);
		for (int i = 2; i < n; i++)
		{
			sold[i] = max(hold[i - 1] + prices[i], sold[i - 1]);
			hold[i] = max(sold[i - 2] - prices[i], hold[i - 1]);
		}
		return sold.back();
	}
};