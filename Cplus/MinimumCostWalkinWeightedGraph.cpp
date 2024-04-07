#include <vector>
using namespace std;

// DSU minimum version
class DSU
{
public:
	DSU(int size) : parent(size), weight(size, -1)
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
		weight[xp] &= weight[yp];
		return true;
	}

	void AddWeight(int p, int w)
	{
		weight[p] &= w;
	}

	int GetWeight(int p)
	{
		return weight[p];
	}

private:
	vector<int> parent;
	vector<int> weight;
};
/********end of DSU minimum version********/

class Solution
{
public:
	vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
	{
		DSU dsu(n);
		for (auto &edge : edges)
		{
			int u = edge[0], v = edge[1], w = edge[2];
			dsu.Union(u, v);
			int p = dsu.Find(u);
			dsu.AddWeight(p, w);
		}
		vector<int> res;
		for (auto &q : query)
		{
			if (q[0] == q[1])
			{
				res.push_back(0);
				continue;
			}
			int x = dsu.Find(q[0]), y = dsu.Find(q[1]);
			if (x != y)
				res.push_back(-1);
			else
				res.push_back(dsu.GetWeight(x));
		}
		return res;
	}
};