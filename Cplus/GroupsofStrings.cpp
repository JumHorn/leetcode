#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int n) : parent(n), rank(n, 1)
	{
		size = n;
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
		--size;
		parent[yr] = xr;
		rank[xr] += rank[yr];
		return true;
	}

	int getMaxCluster()
	{
		int res = 1;
		for (int i = 0; i < (int)rank.size(); ++i)
		{
			if (parent[i] == i && rank[i] > res)
				res = rank[i];
		}
		return res;
	}

	int countGroup()
	{
		return size;
	}

private:
	vector<int> parent;
	vector<int> rank;
	int size;
};

class Solution
{
public:
	vector<int> groupStrings(vector<string> &words)
	{
		int N = words.size();
		unordered_map<int, int> m; //{mask,index}
		vector<int> v;
		DSU dsu(N);
		for (int i = 0; i < N; ++i)
		{
			int mask = 0;
			for (auto c : words[i])
				mask |= 1 << (c - 'a');
			if (m.count(mask) == 0)
				m[mask] = i;
			else
				dsu.Union(m[mask], i);
			v.push_back(mask);
		}
		for (int k = 0; k < N; ++k)
		{
			int mask = v[k];
			// add/delete
			for (int i = 0; i < 26; ++i)
			{
				auto it = m.find(mask ^ (1 << i));
				if (it != m.end())
					dsu.Union(k, it->second);
			}
			// replace
			for (int i = 0; i < 26; ++i)
			{
				if (mask & (1 << i))
					continue;
				for (int j = 0; j < 26; ++j)
				{
					if (mask & (1 << j))
					{
						auto it = m.find(mask ^ (1 << i) ^ (1 << j));
						if (it != m.end())
							dsu.Union(k, it->second);
					}
				}
			}
		}

		return {dsu.countGroup(), dsu.getMaxCluster()};
	}
};