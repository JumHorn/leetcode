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
				long diff = (long)A[i] - A[j];
				if (diff < INT_MIN || diff > INT_MAX)
					continue;
				auto iter = dp[j].find(diff);
				int count = iter == dp[j].end() ? 0 : iter->second;
				dp[i][diff] += count + 1;
				res += count;
			}
		}
		return res;
	}
};