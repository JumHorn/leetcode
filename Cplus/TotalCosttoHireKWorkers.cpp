#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	long long totalCost(vector<int> &costs, int k, int candidates)
	{
		long long res = 0, N = costs.size();
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q1, q2; //{cost,index}
		int i = 0, j = N - 1;
		for (; i < candidates; ++i)
			q1.push({costs[i], i});
		for (; j >= i && N - 1 - j < candidates; --j)
			q2.push({costs[j], j});

		while (--k >= 0)
		{
			if (q1.empty())
			{
				res += q2.top().first;
				q2.pop();
				continue;
			}
			if (q2.empty())
			{
				res += q1.top().first;
				q1.pop();
				continue;
			}
			if (q1.top() < q2.top())
			{
				res += q1.top().first;
				q1.pop();
				if (i <= j)
				{
					q1.push({costs[i], i});
					++i;
				}
			}
			else
			{
				res += q2.top().first;
				q2.pop();
				if (i <= j)
				{
					q2.push({costs[j], j});
					--j;
				}
			}
		}
		return res;
	}
};