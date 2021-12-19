#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	long long getDescentPeriods(vector<int> &prices)
	{
		int N = prices.size();
		vector<int> dp(N);
		dp[0] = 1;
		for (int i = 1; i < N; ++i)
		{
			if (prices[i] - prices[i - 1] == -1)
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = 1;
		}
		return accumulate(dp.begin(), dp.end(), 0LL);
	}
};