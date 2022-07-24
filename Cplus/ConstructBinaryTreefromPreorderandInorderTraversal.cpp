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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		int pre = 0, in = 0;
		return recursive(preorder, pre, inorder, in, INT_MIN);
	}

	TreeNode *recursive(vector<int> &preorder, int &pre, vector<int> &inorder, int &in, int stop)
	{
		if (in >= (int)inorder.size() || inorder[in] == stop)
			return nullptr;
		TreeNode *root = new TreeNode(preorder[pre++]);
		root->left = recursive(preorder, pre, inorder, in, root->val);
		++in;
		root->right = recursive(preorder, pre, inorder, in, stop);
		return root;
	}
};