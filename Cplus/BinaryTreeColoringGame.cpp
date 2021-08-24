#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	bool btreeGameWinningMove(TreeNode *root, int n, int x)
	{
		TreeNode *node = getXNode(root, x);
		int left = nodeCount(node->left), right = nodeCount(node->right);
		return max({left, right, n - left - right - 1}) * 2 > n;
	}

	TreeNode *getXNode(TreeNode *root, int x)
	{
		if (root == nullptr || root->val == x)
			return root;
		TreeNode *res = nullptr;
		res = getXNode(root->left, x);
		if (res == nullptr)
			res = getXNode(root->right, x);
		return res;
	}

	int nodeCount(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		return nodeCount(root->left) + nodeCount(root->right) + 1;
	}
};