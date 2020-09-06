#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int size) : parent(size), rank(size, 1)
	{
		for (int i = 0; i < size; i++)
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

	bool fullTraversal()
	{
		int size = parent.size() - 1;
		return rank[Find(1)] == size;
	}

private:
	vector<int>
		parent;
	vector<int> rank;
};

class Solution
{
public:
	int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
	{
		vector<vector<int>> type(3);
		for (int i = 0; i < (int)edges.size(); ++i)
			type[edges[i][0] - 1].push_back(i);
		vector<int> mark(n + 1);
		int edgeAdded = 0;
		DSU alice(n + 1), bob(n + 1);
		for (int i = 0; i < type[2].size(); ++i)
		{
			if (alice.Union(edges[type[2][i]][1], edges[type[2][i]][2]) | bob.Union(edges[type[2][i]][1], edges[type[2][i]][2]))
				++edgeAdded;
		}
		for (int i = 0; i < type[0].size(); ++i)
		{
			if (alice.Union(edges[type[0][i]][1], edges[type[0][i]][2]))
				++edgeAdded;
		}
		for (int i = 0; i < type[1].size(); ++i)
		{
			if (bob.Union(edges[type[1][i]][1], edges[type[1][i]][2]))
				++edgeAdded;
		}
		return (!alice.fullTraversal() || !bob.fullTraversal()) ? -1 : edges.size() - edgeAdded;
	}
};