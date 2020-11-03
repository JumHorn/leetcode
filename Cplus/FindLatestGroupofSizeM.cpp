#include <unordered_set>
#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int size) : parent(size), rank(size, 1)
	{
		for (int i = 0; i < size; ++i)
			parent[i] = i;
		maxrank = 1;
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
		if (rank[xr] > maxrank)
		{
			maxrank = rank[xr];
		}
		node.erase(yr);
		return true;
	}

	void insertNode(int n)
	{
		node.insert(n);
	}

	bool Check(int m)
	{
		if (maxrank < m)
			return false;
		vector<int> remove;
		for (auto n : node)
		{
			if (rank[n] == m)
				return true;
			if (rank[n] > m)
				remove.push_back(n);
		}
		for (auto r : remove)
			node.erase(r);
		return false;
	}

private:
	vector<int> parent;
	vector<int> rank;
	unordered_set<int> node;
	int maxrank;
};

class Solution
{
public:
	int findLatestStep(vector<int> &arr, int m)
	{
		int N = arr.size();
		vector<int> binarr(N + 1);
		DSU dsu(N + 1);
		for (int i = 0; i < m - 1; ++i)
		{
			binarr[arr[i]] = 1;
			dsu.insertNode(arr[i]);
			if (arr[i] - 1 >= 0 && binarr[arr[i] - 1] == 1)
				dsu.Union(arr[i], arr[i] - 1);
			if (arr[i] + 1 <= N && binarr[arr[i] + 1] == 1)
				dsu.Union(arr[i], arr[i] + 1);
		}
		int res = -1;
		for (int i = m - 1; i < N; ++i)
		{
			binarr[arr[i]] = 1;
			dsu.insertNode(arr[i]);
			if (arr[i] - 1 >= 0 && binarr[arr[i] - 1] == 1)
				dsu.Union(arr[i], arr[i] - 1);
			if (arr[i] + 1 <= N && binarr[arr[i] + 1] == 1)
				dsu.Union(arr[i], arr[i] + 1);
			if (dsu.Check(m))
				res = i + 1;
		}
		return res;
	}
};