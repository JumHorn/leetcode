#include <unordered_set>
#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int s) : parent(s)
	{
		for (int i = 0; i < s; ++i)
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
	int removeStones(vector<vector<int>> &stones)
	{
		int N = stones.size();
		DSU dsu(20000);
		//for each point, union two indexes.
		for (auto &stone : stones)
			dsu.Union(stone[0], stone[1] + 10000);
		unordered_set<int> seen;
		for (auto &stone : stones)
			seen.insert(dsu.Find(stone[0]));
		return N - seen.size();
	}
};