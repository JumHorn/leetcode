#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
	{
		vector<vector<vector<pair<int, int>>>> dp(n + 1, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, {-1, -1})));
		auto res = memdp(n, firstPlayer - 1, secondPlayer - 1, dp);
		return {res.first, res.second};
	}

	pair<int, int> memdp(int n, int first, int second, vector<vector<vector<pair<int, int>>>> &dp)
	{
		if (first + second == n - 1)
			return {1, 1};
		if (dp[n][first][second].first != -1)
			return dp[n][first][second];
		int half = n / 2, halfmask = (1 << half) - 1;
		pair<int, int> res = {INT_MAX, INT_MIN};
		for (int right = halfmask; right >= 0; --right)
		{
			int newmask = right;
			for (int k = 0; k < half; ++k)
			{
				if ((right & (1 << k)) == 0)
					newmask |= (1 << (n - k - 1));
			}

			if (n % 2 == 1)
				newmask |= (1 << (n / 2));

			if ((newmask & (1 << first)) == 0)
			{
				newmask |= (1 << first);
				newmask ^= (1 << (n - first - 1));
			}
			if ((newmask & (1 << second)) == 0)
			{
				newmask |= (1 << second);
				newmask ^= (1 << (n - second - 1));
			}

			int i = -1, j = -1, index = -1;
			for (int k = 0; k < n; ++k)
			{
				if (newmask & (1 << k))
				{
					++index;
					if (k == first)
						i = index;
					else if (k == second)
						j = index;
				}
			}
			auto tmp = memdp((n + 1) / 2, i, j, dp);
			res.first = min(res.first, tmp.first + 1);
			res.second = max(res.second, tmp.second + 1);
		}
		return dp[n][first][second] = res;
	}
};