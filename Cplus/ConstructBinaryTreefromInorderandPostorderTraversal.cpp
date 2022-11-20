#include <climits>
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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		int in = (int)inorder.size() - 1, post = (int)postorder.size() - 1;
		return recursive(inorder, in, postorder, post, INT_MIN);
	}

	TreeNode *recursive(vector<int> &inorder, int &in, vector<int> &postorder, int &post, int stop)
	{
		if (in < 0 || inorder[in] == stop)
			return nullptr;
		TreeNode *root = new TreeNode(postorder[post--]);
		root->right = recursive(inorder, in, postorder, post, root->val);
		--in;
		root->left = recursive(inorder, in, postorder, post, stop);
		return root;
	}
};