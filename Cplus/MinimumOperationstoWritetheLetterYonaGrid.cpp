#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumOperationsToWriteY(vector<vector<int>> &grid)
	{
		vector<int> count(3);
		for (auto &v : grid)
		{
			for (auto n : v)
				++count[n];
		}
		int N = grid.size(), y = N / 2 * 3 + 1;
		vector<int> v(3);
		// center
		--count[grid[N / 2][N / 2]];
		++v[grid[N / 2][N / 2]];
		for (int i = 1; i <= N / 2; ++i)
		{
			int dx = N / 2, dy = N / 2;
			// vertival
			--count[grid[dx + i][dy]];
			++v[grid[dx + i][dy]];
			// top left
			--count[grid[dx - i][dy - i]];
			++v[grid[dx - i][dy - i]];
			// top right
			--count[grid[dx - i][dy + i]];
			++v[grid[dx - i][dy + i]];
		}
		int res = INT_MAX;
		for (int i = 0; i < 3; ++i)
		{
			int op = y - v[i];
			for (int j = 0; j < 3; ++j)
			{
				if (i != j)
					res = min(res, op + N * N - y - count[j]);
			}
		}
		return res;
	}
};