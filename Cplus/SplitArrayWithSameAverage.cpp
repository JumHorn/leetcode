#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool splitArraySameAverage(vector<int> &A)
	{
		int N = A.size(), m = N / 2;
		int sum = accumulate(A.begin(), A.end(), 0);
		// early pruning
		bool isPossible = false;
		for (int i = 1; i <= m && !isPossible; ++i)
		{
			if (sum * i % N == 0)
				isPossible = true;
		}
		if (!isPossible)
			return false;
		vector<unordered_set<int>> dp(m + 1);
		dp[0].insert(0);
		for (auto n : A)
		{
			for (int i = m; i > 0; --i)
			{
				for (auto iter : dp[i - 1])
					dp[i].insert(iter + n);
			}
		}
		for (int i = 1; i <= m; ++i)
		{
			if (sum * i % N == 0 && dp[i].find(sum * i / N) != dp[i].end())
				return true;
		}
		return false;
	}
};