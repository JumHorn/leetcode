#include <vector>
using namespace std;

//Kadane's Algorithm

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int res = 0, maxval = 0;
		for (int i = 1; i < (int)prices.size(); ++i)
		{
			maxval += prices[i] - prices[i - 1];
			if (maxval < 0)
				maxval = 0;
			if (maxval > res)
				res = maxval;
		}
		return res;
	}
};
