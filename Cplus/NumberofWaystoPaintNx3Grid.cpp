#include <vector>
using namespace std;

class Solution
{
public:
	int numOfWays(int n)
	{
		vector<vector<int>> grid(n + 1, vector<int>(4));
		return memdp(grid, 0);
	}

	int memdp(vector<vector<int>> &grid, int k)
	{
		int n = grid.size(), i = k / 3 + 1, j = k % 3 + 1;
		if (k == (n - 1) * 3)
			return 1;
		int res = 0;
		for (int color = 1; color <= 3; color++)
		{
			if (color == grid[i - 1][j] || color == grid[i][j - 1])
				continue;
			grid[i][j] = color;
			res = (res + memdp(grid, k + 1)) % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};