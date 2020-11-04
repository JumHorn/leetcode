#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int countTriplets(vector<int> &arr)
	{
		int N = arr.size(), res = 0;
		vector<unordered_map<int, int>> dp(N + 1);
		for (int i = 0; i < N - 1; ++i)
		{
			dp[i + 1][arr[i]] += 1;
			for (auto &n : dp[i])
				dp[i + 1][n.first ^ arr[i]] += dp[i][n.first];
			int XOR = 0;
			for (int j = i + 1; j < N; ++j)
			{
				XOR ^= arr[j];
				res += dp[i + 1][XOR];
			}
		}
		return res;
	}
};