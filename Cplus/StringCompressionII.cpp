#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int memdp(string &s, int index, int k, vector<vector<int>> &dp)
	{
		int n = s.length();
		if (k < 0)
			return n; //invalid
		if (index >= n || n - index <= k)
			return 0; //empty
		if (dp[index][k] != -1)
			return dp[index][k];
		dp[index][k] = n;
		int count[26] = {0};
		for (int i = index, most = 0; i < n; ++i)
		{
			most = max(most, ++count[s[i] - 'a']); //most freq occur
			//keep most chars and remove all the others
			dp[index][k] = min(dp[index][k], 1 + numLen(most) + memdp(s, i + 1, k - (i - index + 1 - most), dp));
		}
		return dp[index][k];
	}

	int numLen(int x)
	{
		if (x == 1)
			return 0;
		if (x < 10)
			return 1;
		if (x < 100)
			return 2;
		return 3;
	}

	int getLengthOfOptimalCompression(string s, int k)
	{
		int n = s.length();
		vector<vector<int>> dp(n, vector<int>(k + 1, -1));
		return memdp(s, 0, k, dp);
	}
};