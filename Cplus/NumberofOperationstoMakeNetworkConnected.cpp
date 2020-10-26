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
		if (parent[x] != x)
			parent[x] = Find(parent[x]);
		return parent[x];
	}

	int Union(int x, int y)
	{
		int xr = Find(x), yr = Find(y);
		if (xr == yr)
			return 1; //extra edge
		parent[yr] = xr;
		return 0;
	}

	int GetConnectedGroups()
	{
		int res = 0;
		for (int i = 0; i < (int)parent.size(); ++i)
		{
			if (parent[i] == i)
				++res;
		}
		return res;
	}

private:
	vector<int> parent;
};

class Solution
{
public:
	int makeConnected(int n, vector<vector<int>> &connections)
	{
		int res = 0;
		DSU dsu(n);
		for (auto &conn : connections)
			res += dsu.Union(conn[0], conn[1]);
		int group = dsu.GetConnectedGroups();
		if (group <= 1)
			return 0;
		if (res < group - 1)
			return -1;
		return group - 1;
	}
};