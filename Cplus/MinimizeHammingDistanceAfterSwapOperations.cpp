#include <unordered_map>
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
	int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
	{
		int N = source.size();
		DSU dsu(N);
		for (auto &allow : allowedSwaps)
			dsu.Union(allow[0], allow[1]);
		int same = 0;
		unordered_map<int, unordered_map<int, int>> m; //{group,{num,count}}
		for (int i = 0; i < N; ++i)
		{
			int group = dsu.Find(i);
			++m[group][source[i]];
		}
		for (int i = 0; i < N; ++i)
		{
			int group = dsu.Find(i);
			if (m[group][target[i]] > 0)
			{
				--m[group][target[i]];
				++same;
			}
		}
		return N - same;
	}
};