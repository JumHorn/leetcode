#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> finalPrices(vector<int>& prices)
	{
		vector<int> res;
		int n = prices.size();
		for (int i = 0; i < n; i++)
		{
			int discount = 0;
			for (int j = i + 1; j < n; j++)
			{
				if (prices[j] <= prices[i])
				{
					discount = prices[j];
					break;
				}
			}
			res.push_back(prices[i] - discount);
		}
		return res;
	}
};
