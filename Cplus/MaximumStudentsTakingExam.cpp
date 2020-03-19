#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxStudents(vector<vector<char>> &seats)
	{
		int n = seats.size(), m = seats[0].size();
		vector<int> mask(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (seats[i][j] == '#')
					mask[i] |= 1 << j;
		}
		vector<vector<int>> dp(n, vector<int>(pow(2, m)));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < pow(2, m); j++)
			{
				//broken seat check
				if ((j & mask[i]) != 0)
					continue;
				//neighber seat check
				int k;
				for (k = 0; k < m - 1; k++)
				{
					if (((j >> k) & 3u) == 3)
						break;
				}
				if (k != m - 1)
					continue;
				//front seat check
				if (i == 0)
				{
					dp[i][j] = bitCount(j);
					continue;
				}
				for (int l = 0; l < pow(2, m); l++)
				{
					if (((~j) & ((j >> 1) | (j << 1)) & l) == 0)
						dp[i][j] = max(dp[i][j], dp[i - 1][l] + bitCount(j));
				}
			}
		}
		return *max_element(dp.back().begin(), dp.back().end());
	}

	int bitCount(int x)
	{
		int res = 0;
		while (x != 0)
		{
			res++;
			x &= x - 1;
		}
		return res;
	}
};