#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int beautifulPartitions(string s, int k, int minLength)
	{
		int N = s.size();
		if (k * minLength > N || !is_prime(s[0]) || is_prime(s[N - 1]))
			return 0;
		vector<vector<int>> dp(k + 1, vector<int>(N + 1));
		dp[0][0] = 1;
		for (int i = 0; i < k; ++i)
		{
			int sum = 0;
			for (int j = (i + 1) * minLength - 1; j + (k - 1 - i) * minLength < N; ++j)
			{
				if (can_partition(s, j - minLength))
					sum = (sum + dp[i][j - minLength + 1]) % MOD;
				if (can_partition(s, j))
					dp[i + 1][j + 1] = sum;
			}
		}
		return dp[k][N];
	}

	bool is_prime(char c)
	{
		return c == '2' || c == '3' || c == '5' || c == '7';
	}

	bool can_partition(string &s, int index)
	{
		return index < 0 || index >= (int)s.size() - 1 || (!is_prime(s[index]) && is_prime(s[index + 1]));
	}

private:
	static const int MOD = 1e9 + 7;
};