#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return {};
		int M = matrix.size(), N = matrix[0].size();
		vector<int> res(M * N);
		int i = 0, j = 0;
		int direction = 1;
		int path[][2][2] = {{{1, 0}, {0, 1}}, {}, {{0, 1}, {1, 0}}};
		for (int k = 0; k < M * N; ++k)
		{
			res[k] = matrix[i][j];
			int dx = i - direction, dy = j + direction;
			if (dx < 0 || dx >= M || dy < 0 || dy >= N)
			{
				dx = i + path[1 + direction][0][0];
				dy = j + path[1 + direction][0][1];
				direction = -direction;
			}
			if (dx < 0 || dx >= M || dy < 0 || dy >= N)
			{
				dx = i + path[1 - direction][1][0];
				dy = j + path[1 - direction][1][1];
			}
			i = dx;
			j = dy;
		}
		return res;
	}
};