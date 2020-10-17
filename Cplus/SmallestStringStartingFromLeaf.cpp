#include <algorithm>
#include <string>
using namespace std;

// Definition for a binary tree node.
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
	string smallestFromLeaf(TreeNode *root)
	{
		return preorder(root, "");
	}

	string preorder(TreeNode *root, string str)
	{
		if (root == nullptr)
			return "~";
		str = string(1, root->val + 'a') + str;
		if (root->left == root->right) //root->left == nullptr && root->right == nullptr
			return str;
		return min(preorder(root->left, str), preorder(root->right, str));
	}
};