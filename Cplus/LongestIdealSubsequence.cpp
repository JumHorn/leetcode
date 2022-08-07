#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestIdealString(string s, int k)
	{
		vector<int> dp(26);
		int res = 0;
		for (auto c : s)
		{
			int i = c - 'a';
			for (int j = max(0, i - k); j <= min(25, i + k); ++j)
				dp[i] = max(dp[i], dp[j]);
			res = max(res, ++dp[i]);
		}
		return res;
	}
};