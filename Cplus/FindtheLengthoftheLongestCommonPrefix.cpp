#include <string>
#include <vector>
using namespace std;

// Trie
class Trie
{
	struct TreeNode
	{
		int count; // number of words ends with this node
		vector<TreeNode *> nodes;

		TreeNode() : count(0), nodes(10, nullptr) {}
	};

public:
	Trie()
	{
		root = new TreeNode();
	}

	/** Inserts a word into the trie. */
	void insert(const string &word)
	{
		TreeNode *node = root;
		for (auto c : word)
		{
			int index = c - '0';
			if (node->nodes[index] == nullptr)
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
		}
		++node->count;
	}

	/** Returns if the word is in the trie. */
	int search(const string &word) const
	{
		return searchNode(word);
	}

private:
	TreeNode *root;

	int searchNode(const string &str) const
	{
		TreeNode *node = root;
		int res = 0;
		for (auto c : str)
		{
			int index = c - '0';
			if (node->nodes[index] == nullptr)
				break;
			node = node->nodes[index];
			++res;
		}
		return res;
	}
};
/********end of Trie********/

class Solution
{
public:
	int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
	{
		Trie trie;
		for (auto n : arr1)
			trie.insert(to_string(n));
		int res = 0;
		for (auto n : arr2)
			res = max(res, trie.search(to_string(n)));
		return res;
	}
};