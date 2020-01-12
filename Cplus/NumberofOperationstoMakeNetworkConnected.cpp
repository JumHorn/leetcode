#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int size) : parent(size)
	{
		for (int i = 0; i < size; i++)
			parent[i] = i;
	}

	~DSU() {}

	int Find(int x)
	{
		if (parent[x] != x)
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

	int GetAlonePart()
	{
		int res = 0;
		for (int i = 0; i < (int)parent.size(); i++)
			if (parent[i] == i)
				res++;
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
		vector<bool> visited(n, false);
		int res = 0, alone = 0;
		DSU dsu(n);
		for (int i = 0; i < (int)connections.size(); i++)
		{
			dsu.Union(connections[i][0], connections[i][1]);
			if (visited[connections[i][0]] && visited[connections[i][1]])
				++res;
			visited[connections[i][0]] = true;
			visited[connections[i][1]] = true;
		}
		alone = dsu.GetAlonePart();
		if (alone <= 1)
			return 0;
		if (res < alone - 1)
			return -1;
		return alone - 1;
	}
};
