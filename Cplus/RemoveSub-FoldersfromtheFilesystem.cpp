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

		TreeNode() : count(0), nodes(128, nullptr) {}
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
			int index = c;
			if (node->nodes[index] == NULL)
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
		}
		++node->count;
	}

	void search(vector<string> &res)
	{
		string instance;
		dfs(root, instance, res);
	}

private:
	void dfs(TreeNode *node, string &instance, vector<string> &res)
	{
		if (node->count > 0)
		{
			res.push_back(instance);
			node->nodes['/'] = nullptr;
		}
		for (int i = 0; i < 128; ++i)
		{
			if (node->nodes[i] != nullptr)
			{
				instance.push_back(i);
				dfs(node->nodes[i], instance, res);
				instance.pop_back();
			}
		}
	}

	TreeNode *root;
};
/********end of Trie********/

class Solution
{
public:
	vector<string> removeSubfolders(vector<string> &folder)
	{
		Trie trie;
		for (auto &f : folder)
			trie.insert(f);
		vector<string> res;
		trie.search(res);
		return res;
	}
};