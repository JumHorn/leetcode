#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int size) : parent(size), rank(size, 1)
	{
		for (int i = 0; i < size; ++i)
			parent[i] = i;
	}

	int Find(int x)
	{
		if (x != parent[x])
			parent[x] = Find(parent[x]);
		return parent[x];
	}

	bool Union(int x, int y)
	{
		int xr = Find(x), yr = Find(y);
		if (xr == yr)
			return false;
		parent[yr] = xr;
		rank[xr] += rank[yr];
		return true;
	}

	int Count(int x)
	{
		return rank[Find(x)];
	}

private:
	vector<int> parent;
	vector<int> rank;
};

class Solution
{
public:
	vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
	{
		int M = grid.size(), N = grid[0].size(), H = hits.size();
		vector<vector<int>> old_grid = grid;
		DSU dsu(M * N + 1);
		for (auto &hit : hits)
			grid[hit[0]][hit[1]] = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
				{
					int index = i * N + j;
					if (i == 0)
						dsu.Union(index, M * N);
					if (i > 0 && grid[i - 1][j] == 1)
						dsu.Union(index, (i - 1) * N + j);
					if (j > 0 && grid[i][j - 1] == 1)
						dsu.Union(index, i * N + j - 1);
				}
			}
		}

		vector<int> res(H);
		for (int i = H - 1; i >= 0; --i)
		{
			int r = hits[i][0];
			int c = hits[i][1];
			int pre = dsu.Count(M * N);
			if (old_grid[r][c] != 0)
			{
				int index = r * N + c;
				//board dfs direction
				int path[5] = {-1, 0, 1, 0, -1};
				for (int k = 0; k < 4; ++k)
				{
					int dr = r + path[k], dc = c + path[k + 1];
					if (dr >= 0 && dr < M && dc >= 0 && dc < N && grid[dr][dc] == 1)
						dsu.Union(index, dr * N + dc);
				}
				if (r == 0)
					dsu.Union(index, M * N);
				grid[r][c] = 1;
				res[i] = max(0, dsu.Count(M * N) - pre - 1);
			}
		}
		return res;
	}
};