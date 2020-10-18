#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxUncrossedLines(vector<int> &A, vector<int> &B)
	{
		int M = A.size(), N = B.size();
		vector<int> dp(N + 1);
		for (int i = 0; i < M; ++i)
		{
			int pre = dp[0];
			for (int j = 0; j < N; ++j)
			{
				int next = dp[j + 1];
				if (A[i] == B[j])
					dp[j + 1] = pre + 1;
				else
					dp[j + 1] = max(dp[j], dp[j + 1]);
				pre = next;
			}
		}
		return dp[N];
	}
};