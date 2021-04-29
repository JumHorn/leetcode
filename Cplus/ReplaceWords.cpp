#include <algorithm>
#include <sstream>
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
	};

public:
	Trie()
	{
		root = new TreeNode();
	}

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

	bool search(const string &word, string &res)
	{
		TreeNode *node = root;
		for (auto c : word)
		{
			int index = c - 'a';
			res.push_back(c);
			if (node->nodes[index] == nullptr)
				return false;
			node = node->nodes[index];
			if (node->count > 0)
				return true;
		}
		return false;
	}

private:
	TreeNode *root;
};

class Solution
{
public:
	string replaceWords(vector<string> &dictionary, string sentence)
	{
		Trie trie;
		for (auto d : dictionary)
			trie.insert(d);
		string token, res;
		stringstream ss(sentence);
		while (ss >> token)
		{
			string prefix;
			if (trie.search(token, prefix))
				res += prefix + " ";
			else
				res += token + " ";
		}
		if (!res.empty())
			res.pop_back();
		return res;
	}
};