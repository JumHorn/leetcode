#include <algorithm>
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

	void search(TreeNode *node, string &prefix, vector<string> &suggest) const
	{
		if (node == nullptr || (int)suggest.size() >= 3)
			return;
		if (node->count > 0)
			suggest.push_back(prefix);
		for (int i = 0; i < 26; ++i)
		{
			if (node->nodes[i] != nullptr)
			{
				prefix.push_back('a' + i);
				search(node->nodes[i], prefix, suggest);
				prefix.pop_back();
			}
		}
	}

	void startsWith(string &searchWord, vector<vector<string>> &suggest)
	{
		TreeNode *node = root;
		string prefix;
		suggest.resize(searchWord.size());
		for (int i = 0; i < (int)searchWord.size(); ++i)
		{
			int index = searchWord[i] - 'a';
			if (node->nodes[index] == nullptr)
				break;
			prefix.push_back(searchWord[i]);
			node = node->nodes[index];
			search(node, prefix, suggest[i]);
		}
	}

private:
	TreeNode *root;
};
/********end of Trie********/

class Solution
{
public:
	vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
	{
		Trie trie;
		for (auto &product : products)
			trie.insert(product);
		vector<vector<string>> res;
		trie.startsWith(searchWord, res);
		return res;
	}
};