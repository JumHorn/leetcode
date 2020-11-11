#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfArithmeticSlices(vector<int> &A)
	{
		int N = A.size(), res = 0;
		vector<vector<int>> dp(N, vector<int>(N));
		unordered_map<int, vector<int>> m; //{value,{index}}
		for (int i = 0; i < N; ++i)
			m[A[i]].push_back(i);
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				long pre = 2L * A[j] - A[i]; //sequence pre.A[j].A[i]
				if (pre < INT_MIN || pre > INT_MAX || m.find(pre) == m.end())
					continue;
				for (auto k : m[pre])
				{
					if (k >= j)
						break;
					dp[i][j] += dp[j][k] + 1;
				}
				res += dp[i][j];
			}
		}
		return res;
	}
};