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
		return recursive(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}

	//[first,last)
	TreeNode *recursive(vector<int> &preorder, int prefirst, int prelast, vector<int> &inorder, int infirst, int inlast)
	{
		if (prefirst >= prelast)
			return nullptr;
		int mi, len;
		for (mi = infirst; mi < inlast; ++mi)
		{
			if (preorder[prefirst] == inorder[mi])
				break;
		}
		len = mi - infirst;
		TreeNode *root = new TreeNode(preorder[prefirst]);
		root->left = recursive(preorder, prefirst + 1, prefirst + 1 + len, inorder, infirst, mi);
		root->right = recursive(preorder, prefirst + 1 + len, prelast, inorder, mi + 1, inlast);
		return root;
	}
};