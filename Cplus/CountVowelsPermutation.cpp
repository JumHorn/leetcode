#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int countVowelPermutation(int n)
	{
		vector<long> dp(5, 1); // a e i o u
		for (int i = 1; i < n; i++)
		{
			vector<long> tmp(dp);
			//a
			dp[0] = (tmp[1] + tmp[2] + tmp[4]) % MOD;
			//e
			dp[1] = (tmp[0] + tmp[2]) % MOD;
			//i
			dp[2] = (tmp[1] + tmp[3]) % MOD;
			//o
			dp[3] = tmp[2];
			//u
			dp[4] = (tmp[2] + tmp[3]) % MOD;
		}
		int res = 0;
		for (int i = 0; i < 5; i++)
			res = (res + dp[i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};