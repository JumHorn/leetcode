#include <algorithm>
#include <climits>
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
	TreeNode *sufficientSubset(TreeNode *root, int limit)
	{
		if (postorder(root, limit))
			return NULL;
		return root;
	}

	bool postorder(TreeNode *root, int limit)
	{
		if (root == NULL)
			return true;
		bool left = postorder(root->left, limit - root->val);
		bool right = postorder(root->right, limit - root->val);
		if (root->left == NULL && root->right == NULL)
			return root->val < limit;
		if (left)
			root->left = NULL;
		if (right)
			root->right = NULL;
		return left && right;
	}
};