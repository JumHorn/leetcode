#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<long long>> row_prefix(M, vector<long long>(N, 1)), row_suffix(M, vector<long long>(N, 1));
		vector<long long> col_prefix(M, 1), col_suffix(M, 1);
		vector<vector<int>> p(M, vector<int>(N));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (j == 0)
					row_prefix[i][j] = grid[i][j];
				else
					row_prefix[i][j] = row_prefix[i][j - 1] * grid[i][j] % MOD;
			}
			for (int j = N - 1; j >= 0; --j)
			{
				if (j == N - 1)
					row_suffix[i][j] = grid[i][j];
				else
					row_suffix[i][j] = row_suffix[i][j + 1] * grid[i][j] % MOD;
			}
		}

		for (int i = 0; i < M; ++i)
		{
			if (i == 0)
				col_prefix[i] = row_suffix[i][0];
			else
				col_prefix[i] = col_prefix[i - 1] * row_suffix[i][0] % MOD;
		}
		for (int i = M - 1; i >= 0; --i)
		{
			if (i == M - 1)
				col_suffix[i] = row_suffix[i][0];
			else
				col_suffix[i] = col_suffix[i + 1] * row_suffix[i][0] % MOD;
		}

		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				long long val = 1;
				if (i > 0)
					val = val * col_prefix[i - 1] % MOD;
				if (i < M - 1)
					val = val * col_suffix[i + 1] % MOD;
				if (j > 0)
					val = val * row_prefix[i][j - 1] % MOD;
				if (j < N - 1)
					val = val * row_suffix[i][j + 1] % MOD;
				p[i][j] = val;
			}
		}
		return p;
	}

private:
	static const int MOD = 12345;
};