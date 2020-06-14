#include <unordered_map>
#include <vector>
using namespace std;

class TreeAncestor
{
public:
	TreeAncestor(int n, vector<int>& parent) : m_parent(parent), cache(n)
	{
	}

	int getKthAncestor(int node, int k)
	{
		if (node != 0 && cache[node].empty())
		{
			if (node != 0 && cache[m_parent[node]].empty())
				getKthAncestor(m_parent[node], k);
			cache[node].push_back(m_parent[node]);
			cache[node].insert(cache[node].end(), cache[m_parent[node]].begin(), cache[m_parent[node]].end());
		}
		if (k - 1 >= (int)cache[node].size())
			return -1;
		return cache[node][k - 1];
	}

private:
	vector<int>& m_parent;
	vector<vector<int>> cache;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
