#include <vector>
using namespace std;

class Solution
{
public:
	bool areSimilar(vector<vector<int>> &mat, int k)
	{
		int M = mat.size(), N = mat[0].size();
		vector<vector<int>> res(M, vector<int>(N));
		for (int j = 0; j < N; ++j)
		{
			for (int i = 0; i < M; ++i)
			{
				if (i % 2 == 1)
					res[i][(j + k) % N] = mat[i][j];
				else
					res[i][(j - k % N + N) % N] = mat[i][j];
			}
		}
		return res == mat;
	}
};