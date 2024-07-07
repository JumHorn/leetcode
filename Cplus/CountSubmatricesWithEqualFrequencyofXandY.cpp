#include<vector>
using namespace std;

class Solution
{
public:
	int numberOfSubmatrices(vector<vector<char>> &grid)
	{
		int M = grid.size(), N = grid[0].size(), res = 0;
		vector<vector<int>> countx(M, vector<int>(N)), county(M, vector<int>(N));
		countChar(grid, countx, 'X');
		countChar(grid, county, 'Y');
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (countx[i][j] > 0 && countx[i][j] == county[i][j])
					++res;
			}
		}
		return res;
	}

	void countChar(vector<vector<char>> &grid, vector<vector<int>> &count, char ch)
	{
		int M = grid.size(), N = grid[0].size(), res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int n = grid[i][j] == ch ? 1 : 0;
				if (i == 0 && j == 0)
					count[i][j] = n;
				else if (i == 0)
					count[i][j] = count[i][j - 1] + n;
				else if (j == 0)
					count[i][j] = count[i - 1][j] + n;
				else
					count[i][j] = count[i - 1][j] + count[i][j - 1] - count[i - 1][j - 1] + n;
			}
		}
	}
};