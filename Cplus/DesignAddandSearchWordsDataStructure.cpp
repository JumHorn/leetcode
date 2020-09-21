#include <string>
#include <vector>
using namespace std;

class WordDictionary
{
	struct TreeNode
	{
		int count; //number of words ends with this node
		vector<TreeNode *> nodes;

		TreeNode() : count(0), nodes(26, nullptr)
		{
		}
	};

public:
	/** Initialize your data structure here. */
	WordDictionary()
	{
		root = new TreeNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word)
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

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word)
	{
		return doSearch(word, 0, root);
	}

private:
	TreeNode *root;

	bool doSearch(const string &str, int index, TreeNode *node)
	{
		for (int i = index; i < (int)str.length(); ++i)
		{
			if (str[i] == '.')
			{
				for (int j = 0; j < 26; ++j)
				{
					if (node->nodes[j] != nullptr && doSearch(str, i + 1, node->nodes[j]))
						return true;
				}
				return false;
			}
			int index = str[i] - 'a';
			if (node->nodes[index] == nullptr)
				return false;
			node = node->nodes[index];
		}
		return node->count > 0;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */