#include <unordered_map>
#include <vector>
using namespace std;

class TreeAncestor
{
public:
	TreeAncestor(int n, vector<int> &parent) : m_parent(parent), cache(n)
	{
		for (int i = 0; i < n; ++i)
			cache[i].push_back(parent[i]);
	}

	int getKthAncestor(int node, int k)
	{
		if (k == 0)
			return node;
		if (node == 0)
			return -1;
		int n = index(k);
		if (n >= (int)cache[node].size())
		{
			int last = 1 << (cache[node].size() - 1);
			int parent = cache[node][cache[node].size() - 1];
			for (int i = last + 1; i <= 1 << n; ++i)
			{
				parent = m_parent[parent];
				if (parent == -1)
					return -1;
				if (bitCount(i) == 1)
				{
					cache[node].push_back(parent);
					int j = cache[node].size() - 1;
					if (cache[cache[node][j - 1]].size() <= j - 1)
						cache[cache[node][j - 1]].push_back(parent);
				}
			}
		}
		return getKthAncestor(cache[node][n], k - (1 << n));
	}

	int bitCount(int n)
	{
		int res = 0;
		while (n != 0)
		{
			++res;
			n &= n - 1;
		}
		return res;
	}

	int index(int n)
	{
		int res = 0;
		if (n == 0)
			return 0;
		while ((1 << res) <= n)
			++res;
		return res - 1;
	}

private:
	vector<int> &m_parent;
	vector<vector<int>> cache;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */