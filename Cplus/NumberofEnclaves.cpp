#include <vector>
using namespace std;

class Solution
{
public:
	int numEnclaves(vector<vector<int>> &A)
	{
		int ones = 0, M = A.size(), N = A[0].size();
		for (auto &v : A)
		{
			for (auto n : v)
				ones += n;
		}
		for (int j = 0; j < N; ++j)
		{
			ones -= dfs(A, 0, j);
			ones -= dfs(A, M - 1, j);
		}
		for (int i = 1; i < M - 1; ++i)
		{
			ones -= dfs(A, i, 0);
			ones -= dfs(A, i, N - 1);
		}
		return ones;
	}

	int dfs(vector<vector<int>> &A, int row, int col)
	{
		int M = A.size(), N = A[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N || A[row][col] == 0)
			return 0;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		A[row][col] = 0;
		int res = 1;
		for (int i = 0; i < 4; ++i)
			res += dfs(A, row + path[i], col + path[i + 1]);
		return res;
	}
};