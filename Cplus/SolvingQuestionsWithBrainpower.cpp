#include <vector>
using namespace std;

class Solution
{
public:
	long long mostPoints(vector<vector<int>> &questions)
	{
		int N = questions.size();
		vector<long long> dp(N + 1);
		for (int i = N - 1; i >= 0; --i)
			dp[i] = max(dp[i + 1], dp[min(i + questions[i][1] + 1, N)] + questions[i][0]);
		return dp[0];
	}
};