#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Trie
class Trie
{
	struct TreeNode
	{
		int index;	// index of string in origin array
		int minlen; // minimum length of string through this node
		unordered_map<int, TreeNode *> nodes;

		TreeNode() : index(-1), minlen(INT_MAX) {}
	};

public:
	Trie()
	{
		root = new TreeNode();
	}

	/** Inserts a word into the trie. */
	void insert(const string &word, int idx)
	{
		TreeNode *node = root;
		int N = word.size();
		if (root->minlen > N)
		{
			root->index = idx;
			root->minlen = N;
		}
		for (int i = N - 1; i >= 0; --i)
		{
			int index = word[i] - 'a';
			if (node->nodes.count(index) == 0)
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
			if (node->minlen > N)
			{
				node->index = idx;
				node->minlen = N;
			}
		}
	}

	/** Returns if the word is in the trie. */
	int search(const string &word) const
	{
		TreeNode *node = root;
		for (auto c : word)
		{
			int index = c - 'a';
			if (node->nodes.count(index) == 0)
				break;
			node = node->nodes[index];
		}
		return node->index;
	}

private:
	TreeNode *root;
};
/********end of Trie********/

class Solution
{
public:
	vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
	{
		Trie trie;
		int N = wordsContainer.size();
		for (int i = 0; i < N; ++i)
			trie.insert(wordsContainer[i], i);
		vector<int> res;
		for (auto &word : wordsQuery)
		{
			reverse(word.begin(), word.end());
			res.push_back(trie.search(word));
		}
		return res;
	}
};