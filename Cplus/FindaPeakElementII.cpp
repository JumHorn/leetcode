#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findPeakGrid(vector<vector<int>> &mat)
	{
		int M = mat.size(), N = mat[0].size(), r = 0, c = 0;
		for (int i = 0; i < N; ++i)
		{
			if (mat[0][i] > mat[r][c])
				c = i;
		}
		for (int i = 1; i < M; ++i)
		{
			if (mat[i][c] < mat[r][c])
				break;
			r = i;
			if (c > 0 && mat[i][c - 1] > mat[r][c])
				c = c - 1;
			else if (c < N - 1 && mat[i][c + 1] > mat[r][c])
				c = c + 1;
		}
		return {r, c};
	}
};