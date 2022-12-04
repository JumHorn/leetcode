#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int size) : parent(size), rank(size, INT_MAX)
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

	bool Union(int x, int y, int weight)
	{
		int xr = Find(x), yr = Find(y);
		rank[xr] = min({rank[xr], rank[yr], weight});
		if (xr == yr)
			return false;
		parent[yr] = xr;
		return true;
	}

	int Score(int x)
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
	int minScore(int n, vector<vector<int>> &roads)
	{
		DSU dsu(n + 1);
		for (auto &r : roads)
			dsu.Union(r[0], r[1], r[2]);
		return dsu.Score(1);
	}
};