#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		int N = s.length();
		if (N < 4 || N > 12)
			return {};
		vector<vector<vector<string>>> dp(N + 1, vector<vector<string>>(5));
		dp[0][0].push_back("");
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j <= i && j < 3; ++j)
			{
				if (canRestore(s, i, j + 1))
				{
					for (int k = 0; k < 4; ++k)
					{
						for (auto &str : dp[i - j][k])
						{
							if (str.empty())
								dp[i + 1][k + 1].push_back(s.substr(i - j, j + 1));
							else
								dp[i + 1][k + 1].push_back(str + '.' + s.substr(i - j, j + 1));
						}
					}
				}
			}
		}
		return dp[N][4];
	}

	bool canRestore(const string &s, int index, int n)
	{
		if (n <= 1)
			return true;
		int val = (s[index - 1] - '0') * 10 + (s[index] - '0');
		if (n == 2)
			return val >= 10;
		//n==3
		val += (s[index - 2] - '0') * 100;
		return val >= 100 && val <= 255;
	}
};