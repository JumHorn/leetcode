#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countTexts(string pressedKeys)
	{
		int N = pressedKeys.length();
		vector<int> keys = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
		vector<int> dp(N + 1);
		dp[N] = 1;
		for (int i = N - 1; i >= 0; --i)
		{
			dp[i] = dp[i + 1];
			int index = pressedKeys[i] - '0';
			for (int j = 1; j + 1 <= keys[index] && i + j < N && pressedKeys[i + j] == pressedKeys[i]; ++j)
				dp[i] = (dp[i] + dp[i + j + 1]) % MOD;
		}
		return dp[0];
	}

private:
	static const int MOD = 1e9 + 7;
};