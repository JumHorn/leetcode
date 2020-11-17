#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool splitArraySameAverage(vector<int> &A)
	{
		int N = A.size();
		int sum = accumulate(A.begin(), A.end(), 0);
		// early pruning
		bool isPossible = false;
		for (int i = 1; i <= N / 2 && !isPossible; ++i)
		{
			if (sum * i % N == 0)
				isPossible = true;
		}
		if (!isPossible)
			return false;
		vector<unordered_set<int>> dp(N / 2 + 1);
		dp[0].insert(0);
		for (auto n : A)
		{
			for (int i = N / 2; i > 0; --i)
			{
				for (auto m : dp[i - 1])
					dp[i].insert(m + n);
			}
		}
		for (int i = 1; i <= N / 2; ++i)
		{
			if (sum * i % N == 0 && dp[i].find(sum * i / N) != dp[i].end())
				return true;
		}
		return false;
	}
};