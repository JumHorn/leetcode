#include <algorithm>
#include <cmath>
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
	int minCostConnectPoints(vector<vector<int>> &points)
	{
		vector<vector<int>> edges;
		int N = points.size();
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
				edges.push_back({weight, i, j});
			}
		}
		sort(edges.begin(), edges.end());
		DSU dsu(N);
		int res = 0;
		for (auto &edge : edges)
		{
			if (dsu.Union(edge[1], edge[2]))
				res += edge[0];
		}
		return res;
	}
};