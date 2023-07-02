#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> findPrimePairs(int n)
	{
		vector<bool> prime(n + 1);
		for (int i = 2; i <= n; ++i)
		{
			if (!prime[i])
			{
				for (int j = i + i; j <= n; j += i)
					prime[j] = true;
			}
		}

		vector<vector<int>> res;
		for (int i = 2; i <= n - i; ++i)
		{
			if (!prime[i] && !prime[n - i])
				res.push_back({i, n - i});
		}
		return res;
	}
};