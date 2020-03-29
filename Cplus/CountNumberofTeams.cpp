#include <vector>
using namespace std;

class Solution
{
public:
	int numTeams(vector<int>& rating)
	{
		int n = rating.size();
		vector<int> dp(n);
		int res = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (rating[j] < rating[i])
				{
					++dp[i];
					res += dp[j];
				}
			}
		}
		vector<int> dp1(n);
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (rating[j] > rating[i])
				{
					++dp1[i];
					res += dp1[j];
				}
			}
		}
		return res;
	}
};
