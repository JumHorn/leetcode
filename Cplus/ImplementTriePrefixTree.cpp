#include <string>
#include <vector>
using namespace std;

class Trie
{
	struct TreeNode
	{
		int count; //number of words ends with this node
		vector<TreeNode *> nodes;

		TreeNode() : count(0), nodes(26, nullptr)
		{
		}
		// ~TreeNode()
		// {
		// 	for (int i = 0; i < 26; ++i)
		// 	{
		// 		if (nodes[i] != nullptr)
		// 			delete nodes[i];
		// 	}
		// }
	};

public:
	/** Initialize your data structure here. */
	Trie()
	{
		root = new TreeNode();
	}

	// ~Trie()
	// {
	// 	if (root != nullptr)
	// 		delete root;
	// }

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		TreeNode *node = root;
		for (auto c : word)
		{
			int index = c - 'a';
			if (node->nodes[index] == NULL)
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
		}
		++node->count;
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		TreeNode *node = searchNode(word);
		return node != nullptr && node->count > 0;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		TreeNode *node = searchNode(prefix);
		return node != nullptr;
	}

private:
	TreeNode *root;

	TreeNode *searchNode(const string &str)
	{
		TreeNode *node = root;
		for (auto c : str)
		{
			int index = c - 'a';
			if (node->nodes[index] == nullptr)
				return nullptr;
			node = node->nodes[index];
		}
		return node;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */