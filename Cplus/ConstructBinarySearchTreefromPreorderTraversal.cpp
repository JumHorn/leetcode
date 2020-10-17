#include <climits>
#include <vector>
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
	TreeNode *bstFromPreorder(vector<int> &preorder)
	{
		int index = 0;
		return preOrder(preorder, index, INT_MAX);
	}

	TreeNode *preOrder(vector<int> &preorder, int &index, int rootval)
	{
		if (index >= (int)preorder.size() || preorder[index] > rootval)
			return nullptr;
		TreeNode *root = new TreeNode(preorder[index++]);
		root->left = preOrder(preorder, index, root->val);
		root->right = preOrder(preorder, index, rootval);
		return root;
	}
};