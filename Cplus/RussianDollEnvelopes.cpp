#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxEnvelopes(vector<vector<int>> &envelopes)
	{
		if (envelopes.empty())
			return 0;
		vector<int> dp(envelopes.size(), 1);
		sort(envelopes.begin(), envelopes.end());
		for (int i = 1; i < (int)dp.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};