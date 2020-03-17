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
		if (parent[x] == x)
			return x;
		return parent[x] = Find(parent[x]);
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
		vector<int> parent(s.length());
		unordered_map<int, string> m;
		for (int i = 0; i < (int)s.length(); i++)
		{
			int p = dsu.Find(i);
			parent[i] = p;
			m[p].push_back(s[i]);
		}
		for (auto &n : m)
			sort(n.second.begin(), n.second.end(), greater<char>());
		for (int i = 0; i < (int)s.length(); i++)
		{
			s[i] = m[parent[i]].back();
			m[parent[i]].pop_back();
		}
		return s;
	}
};

