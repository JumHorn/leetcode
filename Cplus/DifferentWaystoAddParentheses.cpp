#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> diffWaysToCompute(string input)
	{
		int N = input.length();
		vector<vector<vector<int>>> dp(N, vector<vector<int>>(N + 1));
		memdp(input, 0, N, dp);
		return dp[0][N];
	}

	void memdp(string &input, int l, int r, vector<vector<vector<int>>> &dp)
	{
		if (!dp[l][r].empty())
			return;
		vector<int> res;
		for (int i = l; i < r; ++i)
		{
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				memdp(input, l, i, dp);
				memdp(input, i + 1, r, dp);
				auto &left = dp[l][i], &right = dp[i + 1][r];
				for (auto n : left)
				{
					for (auto m : right)
					{
						if (input[i] == '+')
							res.push_back(n + m);
						else if (input[i] == '-')
							res.push_back(n - m);
						else
							res.push_back(n * m);
					}
				}
			}
		}
		if (res.empty())
			res.push_back(stoi(input.substr(l, r - l)));
		dp[l][r] = res;
	}
};