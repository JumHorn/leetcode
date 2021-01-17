#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int largestSubmatrix(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size();
		for (int i = 1; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (matrix[i][j] == 0)
					matrix[i][j] = 0;
				else
					matrix[i][j] += matrix[i - 1][j];
			}
		}
		int res = 0;
		for (int i = 0; i < M; ++i)
		{
			sort(matrix[i].begin(), matrix[i].end());
			int area = 0;
			for (int j = N - 1; j >= 0 && matrix[i][j] > 0; --j)
				area = max(area, matrix[i][j] * (N - j));
			res = max(res, area);
		}
		return res;
	}
};