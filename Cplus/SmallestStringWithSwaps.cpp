#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int size) : parent(size)
	{
		for (int i = 0; i < size; i++)
			parent[i] = i;
	}

	int Find(int x)
	{
		if (x == parent[x])
			return x;
		return Find(parent[x]);
	}

	bool Union(int x, int y)
	{
		int px = Find(x), py = Find(y);
		if (px == py)
			return false;
		parent[px] = py;
		return true;
	}

private:
	vector<int> parent;
};

class Solution
{
public:
	string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
	{
		DSU dsu(s.length());
		for (auto &p : pairs)
			dsu.Union(p[0], p[1]);
		unordered_map<int, vector<int>> m;
		unordered_map<int, string> m2;
		for (int i = 0; i < (int)s.length(); i++)
		{
			int p = dsu.Find(i);
			m[p].push_back(i);
			m2[p].push_back(s[i]);
		}
		for (auto &n : m)
			sort(n.second.begin(), n.second.end());
		for (auto &n : m2)
			sort(n.second.begin(), n.second.end());
		for (auto &n : m)
		{
			for (int i = 0; i < (int)n.second.size(); i++)
				s[n.second[i]] = m2[n.first][i];
		}
		return s;
	}
};