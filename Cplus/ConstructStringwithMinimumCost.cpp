#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// Trie
class Trie
{
	struct TreeNode
	{
		int count; // number of words ends with this node
		int cost;  // cost with this node
		vector<TreeNode *> nodes;

		TreeNode() : count(0), cost(0), nodes(26, nullptr) {}
	};

public:
	Trie(vector<int> &dp) : dp(dp)
	{
		root = new TreeNode();
	}

	/** Inserts a word into the trie. */
	void insert(const string &word, int cost)
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
		if (node->cost == 0)
			node->cost = cost;
		else
			node->cost = min(node->cost, cost);
	}

	/** Returns if the word is in the trie. */
	bool search(const string &word, int index) const
	{
		TreeNode *node = searchNode(word, index);
		return node != nullptr && node->count > 0;
	}

private:
	TreeNode *root;
	vector<int> &dp;

	TreeNode *searchNode(const string &str, int ind) const
	{
		TreeNode *node = root;
		for (int i = ind; i >= 0; --i)
		{
			int index = str[i] - 'a';
			if (node->nodes[index] == nullptr)
				return nullptr;
			node = node->nodes[index];
			if (node->count > 0 && dp[i] != -1)
			{
				if (dp[ind + 1] == -1)
					dp[ind + 1] = dp[i] + node->cost;
				else
					dp[ind + 1] = min(dp[ind + 1], dp[i] + node->cost);
			}
		}
		return node;
	}
};
/********end of Trie********/

class Solution
{
public:
	int minimumCost(string target, vector<string> &words, vector<int> &costs)
	{
		vector<int> dp(target.size() + 1, -1);
		dp[0] = 0;
		Trie trie(dp);
		int N = words.size();
		for (int i = 0; i < N; ++i)
		{
			reverse(words[i].begin(), words[i].end());
			trie.insert(words[i], costs[i]);
		}
		for (int i = 0; i < target.size(); ++i)
			trie.search(target, i);
		return dp.back();
	}
};