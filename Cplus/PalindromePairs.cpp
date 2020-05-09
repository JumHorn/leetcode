#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution
{
	struct TreeNode
	{
		int index;
		TreeNode *node[26];
		TreeNode() : index(-1)
		{
			memset(node, 0, sizeof(node));
		}
		// ~TreeNode()
		// {
		// 	for(int i=0;i<26;i++)
		// 		if(node[i]!=NULL)
		// 			delete node[i];
		// }
	};

	TreeNode *root;

public:
	vector<vector<int>> palindromePairs(vector<string> &words)
	{
		vector<vector<int>> res;
		root = new TreeNode();
		for (int i = 0; i < (int)words.size(); i++)
			insert(words[i], i);
		for (int i = 0; i < (int)words.size(); i++)
		{
			TreeNode *tmp = root;
			if (root->index >= 0 && i != root->index && isPalindrome(words[i], 0, words[i].length()))
				res.push_back({i, root->index});
			for (int j = 0; j < (int)words[i].length(); j++)
			{
				tmp = tmp->node[words[i][j] - 'a'];
				if (tmp == NULL)
					break;
				if (tmp->index >= 0 && tmp->index != i && isPalindrome(words[i], j + 1, words[i].length()))
					res.push_back({i, tmp->index});
			}
			search(res, tmp, i, words);
		}
		return res;
	}

	void search(vector<vector<int>> &res, TreeNode *root, int index, vector<string> &words)
	{
		if (root == NULL)
			return;
		if (root->index >= 0 && words[index].length() != words[root->index].length() && isPalindrome(words[root->index], 0, words[root->index].length() - words[index].length()))
			res.push_back({index, root->index});
		for (int i = 0; i < 26; i++)
			search(res, root->node[i], index, words);
	}

	void insert(const string &word, int index)
	{
		if (word.empty())
		{
			root->index = index;
			return;
		}
		TreeNode *tmp = root;
		for (int i = word.length() - 1; i >= 0; i--)
		{
			int j = word[i] - 'a';
			if (tmp->node[j] == NULL)
				tmp->node[j] = new TreeNode();
			tmp = tmp->node[j];
		}
		tmp->index = index;
	}

	bool isPalindrome(const string &word, int start, int end)
	{
		--end;
		while (start < end)
		{
			if (word[start++] != word[end--])
				return false;
		}
		return true;
	}
};