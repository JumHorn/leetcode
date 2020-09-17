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
		return recursive(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}

	//[first,last)
	TreeNode *recursive(vector<int> &inorder, int infirst, int inlast, vector<int> &postorder, int postfirst, int postlast)
	{
		if (infirst >= inlast)
			return nullptr;
		int mi, len;
		for (mi = infirst; mi < inlast; ++mi)
		{
			if (postorder[postlast - 1] == inorder[mi])
				break;
		}
		len = mi - infirst;
		TreeNode *root = new TreeNode(postorder[postlast - 1]);
		root->left = recursive(inorder, infirst, mi, postorder, postfirst, postfirst + len);
		root->right = recursive(inorder, mi + 1, inlast, postorder, postfirst + len, postlast - 1);
		return root;
	}
};