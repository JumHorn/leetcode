#include <vector>
using namespace std;

class Solution
{
public:
	int numOfWays(int n)
	{
		//get initial state
		vector<vector<int>> init;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					if (i != j && j != k)
						init.push_back({i, j, k});
		}
		int size = init.size();
		if (n == 1)
			return size;
		//get state transition
		vector<vector<int>> state(size);
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (transState(init[i], init[j]))
					state[i].push_back(j);
			}
		}
		//dp
		vector<int> dp(size, 1);
		for (int i = 1; i < n; ++i)
		{
			vector<int> tmp(size);
			for (int j = 0; j < size; ++j)
			{
				for (int k = 0; k < (int)state[j].size(); ++k)
					tmp[state[j][k]] = (tmp[state[j][k]] + dp[j]) % MOD;
			}
			dp = tmp;
		}
		int res = 0;
		for (auto n : dp)
			res = (res + n) % MOD;
		return res;
	}

private:
	bool transState(vector<int> &a, vector<int> &b)
	{
		for (int i = 0; i < (int)a.size(); ++i)
			if (a[i] == b[i])
				return false;
		return true;
	}

	static const int MOD = 1e9 + 7;
};
