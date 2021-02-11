#include <vector>
using namespace std;

class Solution
{
public:
	void setZeroes(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size();
		bool row = false;
		for (int i = 0; i < M; ++i)
		{
			if (matrix[i][0] == 0)
				row = true;
			for (int j = 1; j < N; ++j)
			{
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
			}
		}

		for (int i = M - 1; i >= 0; --i)
		{
			for (int j = 1; j < N; ++j)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
			if (row)
				matrix[i][0] = 0;
		}
	}
};