#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> findFarmland(vector<vector<int>> &land)
	{
		int M = land.size(), N = land[0].size();
		vector<vector<int>> res;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (land[i][j] == 1)
				{
					vector<int> coor = {i, j, i, j};
					dfs(land, i, j, coor);
					res.push_back(coor);
				}
			}
		}
		return res;
	}

	void dfs(vector<vector<int>> &land, int r, int c, vector<int> &coor)
	{
		int M = land.size(), N = land[0].size();
		if (r < 0 || r >= M || c < 0 || c >= N || land[r][c] == 0)
			return;
		land[r][c] = 0;
		coor[0] = min(coor[0], r);
		coor[1] = min(coor[1], c);
		coor[2] = max(coor[2], r);
		coor[3] = max(coor[3], c);
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
			dfs(land, r + path[i], c + path[i + 1], coor);
	}
};