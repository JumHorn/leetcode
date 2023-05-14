#include <set>
#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int n) : parent(n), rank(n, 1), edge(n)
	{
		size = n;
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
		++edge[xr];
		if (xr == yr)
			return false;
		--size;
		parent[yr] = xr;
		rank[xr] += rank[yr];
		edge[xr] += edge[yr];
		return true;
	}

	int countGroup()
	{
		int res = 0;
		for (int i = 0; i < rank.size(); ++i)
		{
			if (i == parent[i])
			{
				if (rank[i] * (rank[i] - 1) / 2 == edge[i])
					++res;
			}
		}
		return res;
	}

private:
	vector<int> parent;
	vector<int> rank;
	vector<int> edge;
	int size;
};

class Solution
{
public:
	int countCompleteComponents(int n, vector<vector<int>> &edges)
	{
		set<pair<int, int>> s;
		for (auto &edge : edges)
		{
			if (edge[0] > edge[1])
				swap(edge[0], edge[1]);
			s.insert({edge[0], edge[1]});
		}

		DSU dsu(n);
		for (auto &edge : s)
			dsu.Union(edge.first, edge.second);
		return dsu.countGroup();
	}
};