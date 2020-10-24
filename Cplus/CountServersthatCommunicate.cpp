#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

//DSU minimum version
class DSU
{
public:
	DSU(int size) : parent(size)
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
		int xp = Find(x), yp = Find(y);
		if (xp == yp)
			return false;
		parent[yp] = xp;
		return true;
	}

private:
	vector<int> parent;
};
/********end of DSU minimum version********/

class Solution
{
public:
	int countServers(vector<vector<int>> &grid)
	{
		int res = 0, M = grid.size(), N = grid[0].size();
		DSU dsu(M + N);
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
					dsu.Union(i, j + M);
			}
		}
		unordered_map<int, int> m;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
					++m[dsu.Find(i)];
			}
		}
		for (auto &n : m)
		{
			if (n.second > 1)
				res += n.second;
		}
		return res;
	}
};