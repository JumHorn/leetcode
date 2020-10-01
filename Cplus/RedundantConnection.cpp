#include <vector>
using namespace std;

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
		int xr = Find(x), yr = Find(y);
		if (xr == yr)
			return false;
		parent[yr] = xr;
		return true;
	}

private:
	vector<int> parent;
};

class Solution
{
public:
	vector<int> findRedundantConnection(vector<vector<int>> &edges)
	{
		DSU dsu(edges.size() + 1);
		for (auto &edge : edges)
		{
			if (!dsu.Union(edge[0], edge[1]))
				return edge;
		}
		return {};
	}
};