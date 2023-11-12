#include <vector>
using namespace std;

// Trie
class Trie
{
	struct TreeNode
	{
		int count; // number of words ends with this node
		vector<TreeNode *> nodes;

		TreeNode() : count(0), nodes(2, nullptr) {}
	};

public:
	Trie()
	{
		root = new TreeNode();
	}

	void insert(int num)
	{
		TreeNode *node = root;
		for (int i = 31; i >= 0; --i)
		{
			int index = ((num >> i) & 1);
			if (!node->nodes[index])
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
			++node->count;
		}
	}

	void remove(int num)
	{
		TreeNode *node = root;
		for (int i = 31; i >= 0 && node != nullptr; --i)
		{
			int index = ((num >> i) & 1);
			if (!node->nodes[index])
				break;
			if (--node->nodes[index]->count == 0)
				node->nodes[index] = nullptr; // memory leak
			node = node->nodes[index];
		}
	}

	int search(int num) const
	{
		TreeNode *node = root;
		int res = 0;
		for (int i = 31; i >= 0 && node != nullptr; --i)
		{
			int index = ((num >> i) & 1);
			if (node->nodes[1 - index])
			{
				res |= 1 << i;
				node = node->nodes[1 - index];
			}
			else
				node = node->nodes[index];
		}
		return res;
	}

private:
	TreeNode *root;
};
/********end of Trie********/

class Solution
{
public:
	vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries)
	{
		int N = parents.size(), M = queries.size(), root = -1;
		vector<vector<int>> graph(N + 1);
		for (int i = 0; i < N; ++i)
		{
			if (parents[i] == -1)
				root = i;
			else
				graph[parents[i]].push_back(i);
		}
		Trie trie;
		trie.insert(root);
		vector<int> res(M);
		vector<vector<pair<int, int>>> query(N); //{val,index}
		for (int i = 0; i < M; ++i)
			query[queries[i][0]].push_back({queries[i][1], i});
		preorder(graph, root, trie, query, res);
		return res;
	}

	void preorder(vector<vector<int>> &graph, int at, Trie &trie, vector<vector<pair<int, int>>> &query, vector<int> &res)
	{
		for (auto [val, i] : query[at])
			res[i] = trie.search(val);
		for (auto to : graph[at])
		{
			trie.insert(to);
			preorder(graph, to, trie, query, res);
			trie.remove(to);
		}
	}
};