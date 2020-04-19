#include <vector>
#include <string>
using namespace std;

class Solution
{
	struct TreeNode
	{
		int count;
		TreeNode *node[26];
		TreeNode() : count(0)
		{
			memset(node, 0, sizeof(node));
		}
		~TreeNode()
		{
			for (int i = 0; i < 26; i++)
				if (node[i] != NULL)
					delete node[i];
		}
	};

	TreeNode *root;

public:
	vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
	{
		vector<string> res;
		if (words.empty())
			return res;
		root = new TreeNode();
		for (int i = 0; i < (int)words.size(); i++)
			insert(words[i]);
		for (int i = 0; i < (int)board.size(); i++)
			for (int j = 0; j < (int)board[0].size(); j++)
				findWords(board, root, i, j);
		dfs(res, "", root);
		return res;
	}

	void findWords(vector<vector<char>> &board, TreeNode *root, int i, int j)
	{
		int M = board.size(), N = board[0].size();
		if (i < 0 || i >= M || j < 0 || j >= N)
			return;
		char c = board[i][j];
		if (c == '#')
			return;
		root = root->node[c - 'a'];
		if (root == NULL)
			return;
		if (root->count == 1)
			root->count = 2;
		board[i][j] = '#';
		findWords(board, root, i + 1, j);
		findWords(board, root, i - 1, j);
		findWords(board, root, i, j + 1);
		findWords(board, root, i, j - 1);
		board[i][j] = c;
	}

	void dfs(vector<string> &res, string s, TreeNode *root)
	{
		if (root == NULL)
			return;
		if (root->count == 2)
			res.push_back(s);
		for (int i = 0; i < 26; i++)
		{
			string tmp = s;
			if (root->node[i] != NULL)
			{
				tmp += 'a' + i;
				dfs(res, tmp, root->node[i]);
			}
		}
	}

	void insert(const string &word)
	{
		TreeNode *tmp = root;
		for (int i = 0; i < (int)word.length(); i++)
		{
			int index = word[i] - 'a';
			if (tmp->node[index] == NULL)
				tmp->node[index] = new TreeNode();
			tmp = tmp->node[index];
		}
		tmp->count++;
	}
};