#include <algorithm>
#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int size) : parent(size), rank(size, 1)
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
		rank[xr] += rank[yr];
		return true;
	}

	void Unset(int x)
	{
		parent[x] = x;
		rank[x] = 1;
	}

	int Count(int x)
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
	vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
	{
		sort(meetings.begin(), meetings.end(), [](vector<int> &lhs, vector<int> &rhs)
			 { return lhs[2] < rhs[2]; });

		DSU dsu(n);
		dsu.Union(0, firstPerson);
		int N = meetings.size();
		for (int i = 0, j = 0; i < N; i = j)
		{
			for (; j < N && meetings[j][2] == meetings[i][2]; ++j)
				dsu.Union(meetings[j][0], meetings[j][1]);
			for (int k = i; k < j; ++k)
			{
				if (dsu.Find(meetings[k][0]) != dsu.Find(0))
				{
					dsu.Unset(meetings[k][0]);
					dsu.Unset(meetings[k][1]);
				}
			}
		}
		vector<int> res;
		for (int i = 0; i < n; ++i)
		{
			if (dsu.Find(i) == dsu.Find(0))
				res.push_back(i);
		}
		return res;
	}
};