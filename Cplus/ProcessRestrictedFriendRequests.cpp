#include <vector>
using namespace std;

//DSU minimum version
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
		int xp = Find(x), yp = Find(y);
		if (xp == yp)
			return false;
		parent[yp] = xp;
		return true;
	}

	bool Try_Union(int x, int y, vector<vector<int>> &restrictions)
	{
		int xp = Find(x), yp = Find(y);
		for (auto &r : restrictions)
		{
			int xp1 = Find(r[0]), yp1 = Find(r[1]);
			if (xp == xp1 && yp == yp1)
				return false;
			if (xp == yp1 && yp == xp1)
				return false;
		}
		return true;
	}

private:
	vector<int> parent;
};
/********end of DSU minimum version********/

class Solution
{
public:
	vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
	{
		DSU dsu(n);
		vector<bool> res;
		for (auto &r : requests)
		{
			res.push_back(dsu.Try_Union(r[0], r[1], restrictions));
			if (res.back())
				dsu.Union(r[0], r[1]);
		}
		return res;
	}
};