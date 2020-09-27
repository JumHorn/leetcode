#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
	{
		int maxprofit = INT_MIN, wait = 0, board = 0, N = customers.size(), res;
		for (int i = 0; i < N || wait > 0; ++i)
		{
			if (i < N)
				wait += customers[i];
			if (wait >= 4)
			{
				if (i < N)
				{
					board += 4;
					wait -= 4;
				}
				else
				{
					board += wait / 4 * 4;
					i += wait / 4 - 1;
					wait %= 4;
				}
			}
			else
			{
				board += wait;
				wait = 0;
			}
			int profit = board * boardingCost - (i + 1) * runningCost;
			if (maxprofit < profit)
			{
				maxprofit = profit;
				res = i + 1;
			}
		}
		return maxprofit < 0 ? -1 : res;
	}
};