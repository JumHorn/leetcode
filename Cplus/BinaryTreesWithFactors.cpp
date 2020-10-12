#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numFactoredBinaryTrees(vector<int> &A)
	{
		sort(A.begin(), A.end());
		unordered_map<int, long> dp;
		int res = 0;
		for (auto n : A)
		{
			dp[n] = 1;
			for (auto m : dp)
			{
				if (n % m.first == 0)
				{
					int val = n / m.first;
					if (dp.find(val) != dp.end())
						dp[n] = (dp[n] + m.second * dp[val] % MOD) % MOD;
				}
			}
			res = (res + dp[n]) % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};