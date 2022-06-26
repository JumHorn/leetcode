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
	long long countPairs(int n, vector<vector<int>> &edges)
	{
		long long res = 0;
		DSU dsu(n);
		for (auto &edge : edges)
			dsu.Union(edge[0], edge[1]);
		for (int i = 0; i < n; ++i)
		{
			if (i == dsu.Find(i))
			{
				long long group = dsu.Count(i);
				res += group * (n - group);
			}
		}
		return res / 2;
	}
};