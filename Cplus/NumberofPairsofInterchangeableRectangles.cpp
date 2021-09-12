#include <map>
#include <vector>
using namespace std;

class DSU
{
public:
	DSU(int size) : parent(size), rank(size, 1)
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
		rank[xr] += rank[yr];
		return true;
	}

	int Count(int x)
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
	long long interchangeableRectangles(vector<vector<int>> &rectangles)
	{
		int N = rectangles.size();
		DSU dsu(N);
		map<pair<int, int>, int> m; //{{w,h},index}
		for (int i = 0; i < N; ++i)
		{
			int w = rectangles[i][0], h = rectangles[i][1];
			int g = gcd(w, h);
			w /= g;
			h /= g;
			if (m.find({w, h}) != m.end())
				dsu.Union(m[{w, h}], i);
			else
				m[{w, h}] = i;
		}
		long long res = 0;
		for (auto &p : m)
		{
			long n = dsu.Count(p.second);
			res += n * (n - 1) / 2;
		}
		return res;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};