#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int findGoodStrings(int n, string s1, string s2, string evil)
	{
		vector<int> kmp(evil.size());
		int dp[501][51][2][2] = {0};
		for (int i = 1, j = 0; i < (int)evil.size(); ++i)
		{
			while (j > 0 && evil[j] != evil[i])
				j = kmp[j - 1];
			if (evil[j] == evil[i])
				++j;
			kmp[i] = j;
		}
		return memdp(s1, s2, evil, 0, 0, 1, 1, kmp, dp);
	}

	int memdp(string &s1, string &s2, string &evil, int n, int k, int up, int low, vector<int> &kmp, int (*dp)[51][2][2])
	{
		if (dp[n][k][up][low] != 0)
			return dp[n][k][up][low];
		if (k >= (int)evil.length())
			return 0;
		if (n >= (int)s1.length())
			return 1;
		int res = 0;
		char from = low ? s1[n] : 'a';
		char to = up ? s2[n] : 'z';
		for (char c = from; c <= to; c++)
		{
			int jump = k;
			while (jump > 0 && c != evil[jump])
				jump = kmp[jump - 1];
			if (c == evil[jump])
				++jump;
			res = (res + memdp(s1, s2, evil, n + 1, jump, up && (c == to), low && (c == from), kmp, dp)) % MOD;
		}
		return dp[n][k][up][low] = res;
	}

private:
	static const int MOD = 1e9 + 7;
};