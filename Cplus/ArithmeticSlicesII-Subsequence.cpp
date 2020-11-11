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
		vector<unordered_map<long, int>> dp(N);
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				long diff = (long)A[i] - A[j], sum = 0;
				if (diff < INT_MIN || diff > INT_MAX)
					continue;
				if (dp[j].find(diff) != dp[j].end())
					sum = dp[j][diff];
				dp[i][diff] += sum + 1;
				res += sum;
			}
		}
		return res;
	}
};