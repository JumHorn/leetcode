#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxStudents(vector<vector<char>> &seats)
	{
		int M = seats.size(), N = seats[0].size();
		vector<int> mask(M);
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (seats[i][j] == '.')
					mask[i] |= 1 << j;
			}
		}
		vector<int> dp(1 << N, -1), dp_pre(1 << N);
		dp[0] = 0;
		for (int k = 0; k < M; ++k)
		{
			copy(dp.begin(), dp.end(), dp_pre.begin());
			for (int i = 0; i < 1 << N; ++i)
			{
				if (dp_pre[i] == -1)
					continue;
				for (int j = mask[k]; j > 0; j = ((j - 1) & mask[k]))
				{
					if ((j & (j << 1)) == 0 && (i & (j << 1)) == 0 && (i & (j >> 1)) == 0)
						dp[j] = max(dp[j], dp_pre[i] + bitCount(j));
				}
				dp[0] = max(dp[0], dp_pre[i]);
			}
		}
		return *max_element(dp.begin(), dp.end());
	}

	int bitCount(int N)
	{
		int res = 0;
		for (; N != 0; N &= N - 1)
			++res;
		return res;
	}
};