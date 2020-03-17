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
		unordered_map<int, vector<int>> m;
		for (int i = 0; i < (int)s.length(); i++)
		{
			int p = dsu.Find(i);
			parent[i] = p;
			m[p].push_back(i);
		}
		for (auto &n : m)
		{
			string str;
			for (auto i : n.second)
				str += s[i];
			sort(str.begin(), str.end());
			int j = 0;
			for (auto i : n.second)
				s[i] = str[j++];
		}
		return s;
	}
};
