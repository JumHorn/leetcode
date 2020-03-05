#include <string>
#include <vector>
using namespace std;

class Trie
{
private:
	struct TreeNode
	{
		int index;
		TreeNode* node[26];
		TreeNode(int v = -1) : index(v)
		{
			for (int i = 0; i < 26; i++)
				node[i] = NULL;
		}
		// ~TreeNode()
		// {
		// 	for(int i=0;i<26;i++)
		// 		if(node[i]!=NULL)
		// 			delete node[i];
		// }
	};

	TreeNode* root;

	void doSearch(vector<int>& v, int* dp, int count, TreeNode* root)
	{
		if (root == NULL)
			return;
		if (root->index != -1 && count == 0)
			v[root->index]++;
		for (int i = 0; i < 26; i++)
		{
			if (root->node[i] == NULL)
				continue;
			if (dp[i] > 0)
			{
				--dp[i];
				doSearch(v, dp, count - 1, root->node[i]);
				++dp[i];
			}
			else
				doSearch(v, dp, count, root->node[i]);
		}
	}

public:
	Trie()
	{
		root = new TreeNode();
	}

	void insert(const string& str, int index)
	{
		TreeNode* tmp = root;
		for (auto n : str)
		{
			if (tmp->node[n - 'a'] == NULL)
				tmp->node[n - 'a'] = new TreeNode();
			tmp = tmp->node[n - 'a'];
		}
		tmp->index = index;
	}

	void search(vector<int>& v, int* dp, int count)
	{
		for (int i = 0; i < 26; i++)
		{
			if (root->node[i] == NULL)
				continue;
			if (dp[i] > 0)
			{
				--dp[i];
				doSearch(v, dp, count - 1, root->node[i]);
				++dp[i];
			}
		}
	}
};

class Solution
{
public:
	vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
	{
		Trie trie;
		int n = puzzles.size();
		vector<int> res(n);
		for (int i = 0; i < n; i++)
			trie.insert(puzzles[i], i);
		for (int i = 0; i < (int)words.size(); i++)
		{
			int dp[26] = {0}, count = 0;
			for (int j = 0; j < (int)words[i].length(); j++)
			{
				if (dp[words[i][j] - 'a'] == 0)
				{
					dp[words[i][j] - 'a'] = 1;
					count++;
				}
			}
			trie.search(res, dp, count);
		}
		return res;
	}
};
