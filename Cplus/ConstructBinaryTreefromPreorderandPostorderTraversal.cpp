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
	TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
	{
		int preIndex = 0, postIndex = 0;
		return recursive(pre, preIndex, post, postIndex);
	}

	//[first,last)
	TreeNode *recursive(vector<int> &preorder, int &preIndex, vector<int> &postorder, int &postIndex)
	{
		TreeNode *root = new TreeNode(preorder[preIndex++]);
		if (root->val != postorder[postIndex])
			root->left = recursive(preorder, preIndex, postorder, postIndex);
		if (root->val != postorder[postIndex])
			root->right = recursive(preorder, preIndex, postorder, postIndex);
		++postIndex;
		return root;
	}
};