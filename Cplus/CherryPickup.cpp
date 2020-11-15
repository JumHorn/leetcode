#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int cherryPickup(vector<vector<int>> &grid)
	{
		int N = grid.size();
		//r1 c1 r2
		vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
		return max(0, memdp(grid, 0, 0, 0, dp));
	}

	int memdp(vector<vector<int>> &grid, int r1, int c1, int r2, vector<vector<vector<int>>> &dp)
	{
		int N = grid.size(), c2 = r1 + c1 - r2;
		if (r1 >= N || c1 >= N || r2 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1)
			return -5000; //max N*N make all results minus
		if (r1 == N - 1 && c1 == N - 1)
			return grid[r1][c1];
		if (dp[r1][c1][r2] != INT_MIN)
			return dp[r1][c1][r2];
		int res = grid[r1][c1];
		if (r1 != r2)
			res += grid[r2][c2];
		res += max({memdp(grid, r1, c1 + 1, r2, dp), memdp(grid, r1, c1 + 1, r2 + 1, dp),
					memdp(grid, r1 + 1, c1, r2, dp), memdp(grid, r1 + 1, c1, r2 + 1, dp)});
		return dp[r1][c1][r2] = res;
	}
};