#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//Trie
class Trie
{
	struct TreeNode
	{
		// string data; //data for current node
		string hash; //hash string for derivative node
		unordered_map<string, TreeNode *> nodes;

		TreeNode() {}
	};

public:
	Trie()
	{
		root = new TreeNode();
	}

	/** Inserts a path into the trie. */
	void insert(vector<string> &path)
	{
		TreeNode *node = root;
		for (auto &str : path)
		{
			if (node->nodes.find(str) == node->nodes.end())
				node->nodes[str] = new TreeNode();
			node = node->nodes[str];
		}
	}

	void updateHash()
	{
		hashCount.clear();
		updateHash(root);
	}

	vector<vector<string>> getPath()
	{
		vector<vector<string>> res;
		vector<string> instance;
		preorder(root, instance, res);
		return res;
	}

private:
	TreeNode *root;
	unordered_map<string, int> hashCount;

	void preorder(TreeNode *root, vector<string> &instance, vector<vector<string>> &res)
	{
		if (root == nullptr)
			return;
		if (hashCount[root->hash] > 1 && root->hash.size() != 2) //empty hash str is "()" so the size is 2
			return;
		if (!instance.empty())
			res.push_back(instance);
		for (auto iter : root->nodes)
		{
			instance.push_back(iter.first);
			preorder(iter.second, instance, res);
			instance.pop_back();
		}
	}

	void updateHash(TreeNode *root)
	{
		if (root == nullptr)
			return;
		root->hash = calcHash(root);
		++hashCount[root->hash];
		for (auto iter : root->nodes)
			updateHash(iter.second);
	}

	string calcHash(TreeNode *root)
	{
		if (root == nullptr)
			return "";
		string res = "(";
		for (auto iter : root->nodes)
		{
			res += iter.first;
			res += calcHash(iter.second);
		}
		res += ")";
		return res;
	}
};
/********end of Trie********/

class Solution
{
public:
	vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
	{
		Trie trie;
		for (auto &p : paths)
			trie.insert(p);
		trie.updateHash();
		return trie.getPath();
	}
};