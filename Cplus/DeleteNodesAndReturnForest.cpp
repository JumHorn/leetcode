#include <list>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
	{
		list<TreeNode*> res;
		bool deletes[1001] = {0};
		for (int i = 0; i < (int)to_delete.size(); i++)
			deletes[to_delete[i]] = true;
		res.push_back(root);
		auto iter = res.begin();
		while (iter != res.end())
		{
			*iter = dfs(*iter, deletes, res);
			++iter;
		}
		for (auto iter = res.begin(); iter != res.end();)
		{
			if (*iter == NULL)
				iter = res.erase(iter);
			else
				++iter;
		}
		return vector<TreeNode*>(res.begin(), res.end());
	}

	TreeNode* dfs(TreeNode* root, bool* deletes, list<TreeNode*>& res)
	{
		if (root == NULL)
			return NULL;
		if (deletes[root->val])
		{
			if (root->left != NULL)
				res.push_back(root->left);
			if (root->right != NULL)
				res.push_back(root->right);
			return NULL;
		}
		root->left = dfs(root->left, deletes, res);
		root->right = dfs(root->right, deletes, res);
		return root;
	}
};
