#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int countSquares(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size();
		int res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (matrix[i][j] != 0 && i != 0 && j != 0)
					matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]});
				res += matrix[i][j];
			}
		}
		return res;
	}
};