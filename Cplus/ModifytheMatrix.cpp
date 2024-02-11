#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size();
		for (int j = 0; j < N; ++j)
		{
			int maxval = -1;
			for (int i = 0; i < M; ++i)
				maxval = max(maxval, matrix[i][j]);
			for (int i = 0; i < M; ++i)
			{
				if (matrix[i][j] == -1)
					matrix[i][j] = maxval;
			}
		}
		return matrix;
	}
};