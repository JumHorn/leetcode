#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeStones(vector<vector<int>> &stones)
	{
		int res = 0, n = stones.size();
		unordered_map<int, int> row, column;
		vector<int> parent(n), rank(n, 1);
		for (int i = 0; i < n; i++)
			parent[i] = i;
		for (int i = 0; i < n; i++)
		{
			if (row.find(stones[i][0]) != row.end())
				Union(i, row[stones[i][0]], parent, rank);
			if (column.find(stones[i][1]) != column.end())
				Union(i, column[stones[i][1]], parent, rank);

			row[stones[i][0]] = i;
			column[stones[i][1]] = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (parent[i] == i)
				res += rank[i] - 1;
		}
		return res;
	}

	bool Union(int i, int j, vector<int> &parent, vector<int> &rank)
	{
		int pi = Find(i, parent);
		int pj = Find(j, parent);
		if (pi == pj)
			return false;
		parent[pj] = parent[pi];
		rank[pi] += rank[pj];
		return true;
	}

	int Find(int i, vector<int> &parent)
	{
		if (parent[i] == i)
			return i;
		return Find(parent[i], parent);
	}
};