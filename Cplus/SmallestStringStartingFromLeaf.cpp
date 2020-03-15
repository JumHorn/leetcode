#include <algorithm>
#include <string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	string smallestFromLeaf(TreeNode *root)
	{
		string tmp, res;
		preorder(root, tmp, res);
		return res;
	}

	void preorder(TreeNode *root, string &tmp, string &res)
	{
		if (root == NULL)
			return;
		tmp.push_back(root->val + 'a');
		if (root->left == NULL && root->right == NULL)
		{
			if (res.empty())
			{
				res = tmp;
				reverse(res.begin(), res.end());
			}
			else
			{
				string t = tmp;
				reverse(t.begin(), t.end());
				res = min(res, t);
			}
		}
		preorder(root->left, tmp, res);
		preorder(root->right, tmp, res);
		tmp.pop_back();
	}
};
