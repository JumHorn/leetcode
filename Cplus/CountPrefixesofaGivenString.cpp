#include <string>
#include <vector>
using namespace std;

//Trie
class Trie
{
	struct TreeNode
	{
		int count; //number of words ends with this node
		vector<TreeNode *> nodes;

		TreeNode() : count(0), nodes(26, nullptr) {}
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
			int index = c - 'a';
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
			int index = c - 'a';
			if (node->nodes[index] == nullptr)
				break;
			node = node->nodes[index];
			res += node->count;
		}
		return res;
	}
};
/********end of Trie********/

class Solution
{
public:
	int countPrefixes(vector<string> &words, string s)
	{
		Trie trie;
		for (auto &word : words)
			trie.insert(word);
		return trie.search(s);
	}
};