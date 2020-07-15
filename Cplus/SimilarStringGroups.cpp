#include <vector>
#include <string>
using namespace std;

class DSU
{
public:
	DSU(int s) : parent(s)
	{
		for (int i = 0; i < s; i++)
			parent[i] = i;
		size = s;
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
		--size;
		parent[yr] = xr;
		return true;
	}

	int countGroup()
	{
		return size;
	}

private:
	vector<int> parent;
	int size;
};

class Solution
{
public:
	int numSimilarGroups(vector<string> &A)
	{
		DSU dsu(A.size());
		for (int i = 0; i < (int)A.size(); i++)
		{
			for (int j = i + 1; j < (int)A.size(); j++)
			{
				if (strDiff(A[i], A[j]))
					dsu.Union(i, j);
			}
		}
		return dsu.countGroup();
	}

	bool strDiff(const string &lhs, const string &rhs)
	{
		int res = 0;
		for (int i = 0; i < (int)lhs.length(); i++)
		{
			if (lhs[i] != rhs[i])
				res++;
		}
		return res == 2 || res == 0;
	}
};