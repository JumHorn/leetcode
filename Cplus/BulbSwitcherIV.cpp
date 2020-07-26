#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minFlips(string target)
	{
		int N = target.length();
		vector<int> dp(N + 1);
		dp[N] = target.back() == '0' ? 1 : 0;
		for (int i = N - 1; i >= 0;)
		{
			while (i >= 0 && '0' == target[i])
			{
				dp[i] = dp[i + 1];
				--i;
			}
			if (i >= 0) //already 1
			{
				int j = i;
				while (j >= 0 && '1' == target[j])
					--j;
				dp[j + 1] = dp[i + 1] + 2;
				i = j;
			}
		}
		return dp[0] - 1;
	}
};