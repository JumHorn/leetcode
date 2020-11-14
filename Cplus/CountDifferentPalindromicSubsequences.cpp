#include <string>
#include <vector>
using namespace std;

/*
Assume that dp[i][j] is the number of different palindromic subsequences in range [i,j]

if s[i] != s[j] so [i,j] is not a palindromic string, we can get rid of either s[i] or s[j]. We have:
dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
we must -dp[i+1][j-1], because the range [i+1, j-1] is calculated twice.

if s[i] == s[j] so
dp[i][j] = dp[i+1][j-1] + s[i] {dp[i+1][j-1]} s[j] - duplicated elements between 2 sets

The most important thing here is to calculate the number of duplicated elements. These elements will be in the range (i1,j1) (a sub range of [i,j]) where:
i1 is the next position to the right from i so that s[i] = s[i1]
j1 is the next position to the left from j so that s[j1] = s[j]

all elements in [i1+1, j1-1] will be duplicated, because:
{s[i1] { [i1+1, j1-1] } s[j1]} == {s[i] { [i1+1, j1-1] } s[j]}
*/

class Solution
{
public:
	int countPalindromicSubsequences(string S)
	{
		int len = S.length();
		vector<vector<int>> dp(len, vector<int>(len));
		vector<int> left = leftNext(S);
		vector<int> right = rightNext(S);
		for (int i = 0; i < len; ++i)
			dp[i][i] = 1;
		for (int n = 1; n < len; ++n)
		{
			for (int i = 0, j = n; i < len - n; i++, j++)
			{
				if (S[i] != S[j])
					dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
				else
				{

					int l = left[i], r = right[j];
					int duplicates = (l < r) ? -dp[l + 1][r - 1] : (r == l) ? 1 : 2;
					dp[i][j] = dp[i + 1][j - 1] * 2 + duplicates;
				}
				dp[i][j] = dp[i][j] < 0 ? dp[i][j] + MOD : dp[i][j] % MOD;
			}
		}
		return dp[0][len - 1];
	}

	vector<int> leftNext(const string &s)
	{
		int n = s.length();
		vector<int> v(26, n), res(n);
		for (int i = n - 1; i >= 0; --i)
		{
			res[i] = v[s[i] - 'a'];
			v[s[i] - 'a'] = i;
		}
		return res;
	}

	vector<int> rightNext(const string &s)
	{
		int n = s.length();
		vector<int> v(26, -1), res(n);
		for (int i = 0; i < n; ++i)
		{
			res[i] = v[s[i] - 'a'];
			v[s[i] - 'a'] = i;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};