#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCost(string s, vector<int> &cost)
	{
		int N = s.length(), res = 0, sum = cost[0], maxval = cost[0];
		for (int i = 1, j = 0; i <= N; ++i)
		{
			if (i == N || s[i] != s[j])
			{
				res += sum - maxval;
				j = i;
				if (i < N)
					maxval = sum = cost[i];
			}
			else
			{
				sum += cost[i];
				maxval = max(maxval, cost[i]);
			}
		}
		return res;
	}
};