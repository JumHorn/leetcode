#include <algorithm>
#include <string>
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
	bool equationsPossible(vector<string> &equations)
	{
		DSU equal(26);
		for (auto &e : equations)
		{
			int a = e[0] - 'a', b = e[3] - 'a';
			if (e[1] == '=')
				equal.Union(a, b);
		}
		for (auto &e : equations)
		{
			int a = e[0] - 'a', b = e[3] - 'a';
			if (e[1] == '!' && equal.Find(a) == equal.Find(b))
				return false;
		}
		return true;
	}
};