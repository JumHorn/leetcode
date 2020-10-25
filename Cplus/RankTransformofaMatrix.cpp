#include <climits>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int size, vector<int> &rank) : parent(size), rank(rank)
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
		rank[xr] = max(rank[xr], rank[yr]);
		return true;
	}

	int getRank(int x)
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
	vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size();
		vector<vector<int>> res(M, vector<int>(N));
		map<int, vector<int>> m; //{value,{pos}}
		vector<int> rank(M + N);
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				m[matrix[i][j]].push_back(i * N + j);
		}
		for (auto &n : m)
		{
			vector<int> &pos = n.second;
			DSU dsu(M + N, rank);
			for (auto &p : pos)
				dsu.Union(p / N, p % N + M);
			for (auto &p : pos)
			{
				int i = p / N, j = p % N;
				rank[i] = rank[j + M] = res[i][j] = dsu.getRank(i) + 1;
			}
		}
		return res;
	}
};