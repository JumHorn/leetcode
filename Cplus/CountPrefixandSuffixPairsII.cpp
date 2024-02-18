#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// Trie
class Trie
{
	struct TreeNode
	{
		int index; // index of origin
		int count; // number of nodes
		vector<TreeNode *> nodes;

		TreeNode() : index(-1), count(0), nodes(26, nullptr) {}
	};

public:
	Trie()
	{
		root = new TreeNode();
	}

	/** Inserts a word into the trie. */
	void insert(const string &word, int index)
	{
		TreeNode *node = root;
		for (auto c : word)
		{
			int index = c - 'a';
			if (node->nodes[index] == nullptr)
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
		}
		++node->count;
		node->index = index;
	}

	/** Returns if the word is in the trie. */
	int search(const string &str, vector<vector<int>> &ztable) const
	{
		TreeNode *node = root;
		int res = 0;
		for (auto c : str)
		{
			int index = c - 'a';
			if (node->nodes[index] == nullptr)
				return 0;
			node = node->nodes[index];
		}
		return searchNode(node, str, ztable);
	}

private:
	TreeNode *root;

	int searchNode(TreeNode *node, const string &str, vector<vector<int>> &ztable) const
	{
		if (node == nullptr)
			return 0;
		int res = 0;
		if (node->index != -1)
		{
			int len = str.size(), P = ztable[node->index].size();

			if (P >= len && ztable[node->index][P - len] >= len)
				res += node->count;
		}
		for (auto n : node->nodes)
			res += searchNode(n, str, ztable);
		return res;
	}
};
/********end of Trie********/

class Solution
{
public:
	long long countPrefixSuffixPairs(vector<string> &words)
	{
		long long res = 0;
		Trie trie;
		vector<vector<int>> ztable(words.size());
		auto z_function = [&](const string &s, int index)
		{
			int N = s.length(), start = 0; // max length prefix at start
			auto &z = ztable[index];
			z.resize(N);
			for (int i = 1; i < N; ++i)
			{
				if (start + z[start] > i)
					z[i] = min(z[i - start], start + z[start] - i);
				while (i + z[i] < N && s[i + z[i]] == s[z[i]])
					++z[i];
				if (start + z[start] < i + z[i])
					start = i;
			}
			z[0] = N;
		};

		int index = 0;
		reverse(words.begin(), words.end());
		for (auto &w : words)
		{
			z_function(w, index);
			res += trie.search(w, ztable);
			trie.insert(w, index);
			++index;
		}
		return res;
	}
};