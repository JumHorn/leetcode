#include <vector>
using namespace std;

class Solution
{
public:
	int minimumArea(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<int> rect = {M, N, 0, 0};
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
				{
					rect[0] = min(rect[0], i);
					rect[1] = min(rect[1], j);
					rect[2] = max(rect[2], i);
					rect[3] = max(rect[3], j);
				}
			}
		}
		return (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
	}
};