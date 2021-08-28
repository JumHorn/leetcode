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
	bool validPath(int n, vector<vector<int>> &edges, int start, int end)
	{
		DSU dsu(n);
		for (auto &edge : edges)
			dsu.Union(edge[0], edge[1]);
		return dsu.Find(start) == dsu.Find(end);
	}
};