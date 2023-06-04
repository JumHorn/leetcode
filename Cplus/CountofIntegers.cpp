#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	int count(string s1, string s2, int min_sum, int max_sum)
	{
		int dp[410][23][2][2] = {0};
		int size = max(s1.size(), s2.size());
		// add prefix zero to s1,s2
		s1 = string(size - s1.size(), '0') + s1;
		s2 = string(size - s2.size(), '0') + s2;

		function<int(string &, string &, int, int, int, int)> memdp = [&](string &s1, string &s2, int n, int up, int low, int sum)
		{
			if (dp[sum][n][up][low] != 0)
				return dp[sum][n][up][low];
			if (sum > max_sum || sum + 9 * (s1.size() - n) < min_sum)
				return 0;
			if (n >= (int)s1.size())
			{
				if (sum >= min_sum && sum <= max_sum)
					return 1;
				return 0;
			}
			int res = 0;
			char from = low ? s1[n] : '0';
			char to = up ? s2[n] : '9';
			for (char c = from; c <= to; ++c)
				res = (res + memdp(s1, s2, n + 1, up && (c == to), low && (c == from), sum + (c - '0'))) % MOD;
			return dp[sum][n][up][low] = res;
		};

		return memdp(s1, s2, 0, 1, 1, 0);
	}

private:
	static const int MOD = 1e9 + 7;
};