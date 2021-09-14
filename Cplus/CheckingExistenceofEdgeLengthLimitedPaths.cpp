#include <algorithm>
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

private:
	vector<int> parent;
};
/********end of DSU minimum version********/

class Solution
{
public:
	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
	{
		int N = queries.size(), j = 0;
		for (int i = 0; i < N; ++i)
			queries[i].push_back(i);
		sort(queries.begin(), queries.end(), *this);
		sort(edgeList.begin(), edgeList.end(), *this);
		DSU dsu(n);
		vector<bool> res(N);
		for (auto &query : queries)
		{
			for (; j < (int)edgeList.size() && edgeList[j][2] < query[2]; ++j)
				dsu.Union(edgeList[j][0], edgeList[j][1]);
			res[query[3]] = dsu.Find(query[0]) == dsu.Find(query[1]);
		}
		return res;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		return lhs[2] < rhs[2];
	}
};