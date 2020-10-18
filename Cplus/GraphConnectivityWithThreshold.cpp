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
	vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries)
	{
		if (threshold == 0)
			return vector<bool>(queries.size(), true);
		DSU dsu(n + 1);
		for (int i = threshold + 1; i <= n; ++i)
		{
			for (int j = i * 2, k = 2; j <= n; j = i * (++k))
			{
				dsu.Union(i, j);
			}
		}

		vector<bool> res;
		for (auto &q : queries)
			res.push_back(dsu.Find(q[0]) == dsu.Find(q[1]));
		return res;
	}
};