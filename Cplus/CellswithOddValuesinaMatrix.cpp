#include <vector>
using namespace std;

class Solution
{
public:
	int oddCells(int n, int m, vector<vector<int>> &indices)
	{
		vector<vector<int>> matrix(n, vector<int>(m));
		for (int k = 0; k < (int)indices.size(); ++k)
		{
			for (int i = 0; i < n; ++i)
				++matrix[i][indices[k][1]];
			for (int j = 0; j < m; ++j)
				++matrix[indices[k][0]][j];
		}
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (matrix[i][j] % 2 == 1)
					++res;
			}
		}
		return res;
	}
};