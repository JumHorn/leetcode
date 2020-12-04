#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix)
	{
		vector<int> res;
		if (matrix.empty() || matrix[0].empty())
			return res;
		int M = matrix.size(), N = matrix[0].size();
		vector<int> range = {0, N, 0, M}; //left,right,bottom,top
		vector<vector<int>> path = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		vector<vector<int>> rangechange = {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, -1, 0, 0}, {0, 0, 0, -1}};

		int i = 0, j = 0, d = 0;
		for (int k = 0; k < M * N; ++k)
		{
			res.push_back(matrix[i][j]);
			int dx = i + path[d][0], dy = j + path[d][1];
			if (dx >= range[2] && dx < range[3] && dy >= range[0] && dy < range[1])
			{
				i = dx;
				j = dy;
			}
			else
			{
				d = (d + 1) % 4;
				i += path[d][0];
				j += path[d][1];
				for (int i = 0; i < 4; ++i)
					range[i] += rangechange[d][i];
			}
		}
		return res;
	}
};