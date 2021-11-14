#include <vector>
using namespace std;

class Solution
{
public:
	int timeRequiredToBuy(vector<int> &tickets, int k)
	{
		int res = 0, N = tickets.size();
		while (tickets[k] > 0)
		{
			for (int i = 0; i < N; ++i)
			{
				if (tickets[i] > 0)
				{
					--tickets[i];
					++res;
					if (tickets[k] == 0)
						return res;
				}
			}
		}
		return res;
	}
};