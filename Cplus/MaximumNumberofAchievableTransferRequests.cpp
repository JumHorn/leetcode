#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumRequests(int n, vector<vector<int>> &requests)
	{
		int N = requests.size(), res = 0;
		for (int mask = 0; mask < 1 << N; ++mask)
		{
			vector<int> indegree(n), outdegree(n);
			for (int i = 0; i < N; ++i)
			{
				if ((1 << i) & mask)
				{
					++outdegree[requests[i][0]];
					++indegree[requests[i][1]];
				}
			}
			if (indegree == outdegree)
				res = max(res, bitCount(mask));
		}
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};