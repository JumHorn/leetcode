#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<pair<int, int>> row, col; //{0,1}
		for (int i = 0; i < M; ++i)
		{
			int one = 0, zero = 0;
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 0)
					++one;
				else
					++zero;
			}
			row.push_back({zero, one});
		}

		for (int j = 0; j < N; ++j)
		{
			int one = 0, zero = 0;
			for (int i = 0; i < M; ++i)
			{
				if (grid[i][j] == 0)
					++one;
				else
					++zero;
			}
			col.push_back({zero, one});
		}

		vector<vector<int>> diff(M, vector<int>(N));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				diff[i][j] = row[i].first + col[j].first - (row[i].second + col[j].second);
			}
		}
		return diff;
	}
};