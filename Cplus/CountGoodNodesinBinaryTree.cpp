#include <algorithm>
#include <climits>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	int goodNodes(TreeNode *root)
	{
		return preorder(root, INT_MIN);
	}

	int preorder(TreeNode *root, int maxval)
	{
		if (root == NULL)
			return 0;
		int res = 0;
		if (root->val >= maxval)
		{
			res = 1;
			maxval = root->val;
		}
		res += preorder(root->left, maxval);
		res += preorder(root->right, maxval);
		return res;
	}
};
