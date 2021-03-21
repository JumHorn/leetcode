#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int getNumberOfBacklogOrders(vector<vector<int>> &orders)
	{
		priority_queue<pair<int, int>> buy; //{price,count}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sell;
		for (auto &order : orders)
		{
			if (order[2] == 0) //buy maxprice
			{
				int a = order[1]; //amount
				while (!sell.empty() && sell.top().first <= order[0] && a > 0)
				{
					if (a >= sell.top().second)
					{
						a -= sell.top().second;
						sell.pop();
					}
					else
					{
						int b = sell.top().second - a;
						int p = sell.top().first;
						sell.pop();
						sell.push({p, b});
						a = 0;
					}
				}
				if (a != 0)
					buy.push({order[0], a});
			}
			else //sell minprice
			{
				int a = order[1];
				while (!buy.empty() && buy.top().first >= order[0] && a > 0)
				{
					if (a >= buy.top().second)
					{
						a -= buy.top().second;
						buy.pop();
					}
					else
					{
						int b = buy.top().second - a;
						int p = buy.top().first;
						buy.pop();
						buy.push({p, b});
						a = 0;
					}
				}
				if (a != 0)
					sell.push({order[0], a});
			}
		}
		long res = 0;
		for (; !buy.empty(); buy.pop())
			res = (res + buy.top().second) % MOD;
		for (; !sell.empty(); sell.pop())
			res = (res + sell.top().second) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};