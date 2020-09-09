#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxStudents(vector<vector<char>> &seats)
	{
		int m = seats.size(), n = seats[0].size();
		vector<int> mask(m);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (seats[i][j] == '.')
					mask[i] |= 1 << j;
			}
		}
		vector<vector<int>> dp(m + 1, vector<int>(1 << n));
		for (int k = 0; k < m; ++k)
		{
			for (int i = 0; i < 1 << n; ++i)
			{
				for (int j = 0; j < 1 << n; ++j)
				{
					if ((j & mask[k]) == j && (j & (j << 1)) == 0 && (i & (j << 1)) == 0 && (i & (j >> 1)) == 0)
						dp[k + 1][j] = max(dp[k + 1][j], dp[k][i] + bitCount(j));
				}
			}
		}
		return *max_element(dp.back().begin(), dp.back().end());
	}

	int bitCount(int n)
	{
		int res = 0;
		while (n != 0)
		{
			++res;
			n &= n - 1;
		}
		return res;
	}
};