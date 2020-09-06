#include <algorithm>
#include <climits>
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
	//all nodes united into a single component
	bool United()
	{
		return rank[Find(0)] == parent.size();
	}

private:
	vector<int> parent;
	vector<int> rank;
};

class Solution
{
public:
	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
	{
		int N = edges.size();
		for (int i = 0; i < N; ++i)
			edges[i].push_back(i);
		sort(edges.begin(), edges.end(), *this);
		int mst = mimimumSpanningTree(n, edges);
		vector<int> critical, pseudo;
		for (int i = 0; i < N; ++i)
		{
			if (mimimumSpanningTree(n, edges, -1, i) > mst)
				critical.push_back(edges[i][3]);
			else if (mimimumSpanningTree(n, edges, i) == mst)
				pseudo.push_back(edges[i][3]);
		}
		return {critical, pseudo};
	}

	int mimimumSpanningTree(int n, vector<vector<int>> &edges, int pre_edge = -1, int block_edge = -1) //kruskal algorithm
	{
		DSU dsu(n);
		int res = 0, count = 0;
		if (pre_edge != -1)
		{
			dsu.Union(edges[pre_edge][0], edges[pre_edge][1]);
			res += edges[pre_edge][2];
			++count;
		}
		for (int i = 0; i < (int)edges.size() && count < n - 1; ++i) //choose n-1 edges
		{
			if (pre_edge == i || block_edge == i)
				continue;
			if (dsu.Union(edges[i][0], edges[i][1]))
			{
				res += edges[i][2];
				++count;
			}
		}
		return dsu.United() ? res : INT_MAX;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		return lhs[2] < rhs[2];
	}
};