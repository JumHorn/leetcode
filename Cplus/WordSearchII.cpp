#include <string>
#include <unordered_set>
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

	vector<string> search(vector<vector<char>> &board)
	{
		int M = board.size(), N = board[0].size();
		string instances;
		unordered_set<string> res;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				dfs(board, root, i, j, instances, res);
		}
		return vector<string>(res.begin(), res.end());
	}

private:
	TreeNode *root;

	void dfs(vector<vector<char>> &board, TreeNode *node, int row, int col, string &instance, unordered_set<string> &res) const
	{
		int M = board.size(), N = board[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N || board[row][col] == '#')
			return;
		char c = board[row][col];
		node = node->nodes[c - 'a'];
		if (node == nullptr)
			return;
		instance.push_back(c);
		if (node->count >= 1)
			res.insert(instance);
		board[row][col] = '#';
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int k = 0; k < 4; ++k)
			dfs(board, node, row + path[k], col + path[k + 1], instance, res);
		board[row][col] = c;
		instance.pop_back();
	}
};
/********end of Trie********/

class Solution
{
public:
	vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
	{
		Trie trie;
		if (words.empty())
			return {};
		for (auto &word : words)
			trie.insert(word);
		return trie.search(board);
	}
};