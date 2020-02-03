#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int videoStitching(vector<vector<int>> &clips, int T)
	{
		const int MAX = clips.size() + 2;
		sort(clips.begin(), clips.end(), *this);
		vector<int> dp(T + 1, MAX);
		for (int i = 0; i < (int)clips.size(); i++)
		{
			for (int j = clips[i][0]; j <= clips[i][1]; j++)
			{
				if (j > T)
					break;
				if (clips[i][0] == 0)
					dp[j] = 1;
				else
					dp[j] = min(dp[j], dp[clips[i][0]] + 1);
			}
		}
		return dp[T] == MAX ? -1 : dp[T];
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		if (lhs[0] != rhs[0])
			return lhs[0] < rhs[0];
		return lhs[1] < rhs[1];
	}
};