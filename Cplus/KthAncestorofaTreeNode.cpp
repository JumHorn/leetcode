#include <unordered_map>
#include <vector>
using namespace std;

class TreeAncestor
{
public:
	TreeAncestor(int n, vector<int> &parent) : m_parent(parent), cache(n, vector<int>(21))
	{
		for (int i = 0; i < n; ++i)
			cache[i][0] = parent[i];
		for (int j = 0; j < 20; ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				if (cache[i][j] == -1)
					cache[i][j + 1] = -1;
				else
					cache[i][j + 1] = cache[cache[i][j]][j];
			}
		}
	}

	int getKthAncestor(int node, int k)
	{
		for (int i = 0; i < 20; ++i)
		{
			if ((k >> i) & 1)
			{
				node = cache[node][i];
				if (node == -1)
					return -1;
			}
		}
		return node;
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