#include <vector>
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
	int pseudoPalindromicPaths(TreeNode *root)
	{
		return preorder(root, 0);
	}

	int preorder(TreeNode *root, int mask)
	{
		if (root == nullptr)
			return 0;
		mask ^= 1 << root->val;
		if (root->left == nullptr && root->right == nullptr)
			return bitCount(mask) < 2 ? 1 : 0;
		int res = 0;
		res += preorder(root->left, mask);
		res += preorder(root->right, mask);
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};