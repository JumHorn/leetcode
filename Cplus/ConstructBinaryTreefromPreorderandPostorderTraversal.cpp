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
		return recursive(pre, 0, pre.size(), post, 0, post.size());
	}

	//[first,last)
	TreeNode *recursive(vector<int> &preorder, int prefirst, int prelast, vector<int> &postorder, int postfirst, int postlast)
	{
		if (prefirst >= prelast)
			return nullptr;
		if (prelast - prefirst == 1)
			return new TreeNode(preorder[prefirst]);
		int mi, len;
		for (mi = postfirst; mi < postlast; ++mi)
		{
			if (preorder[prefirst + 1] == postorder[mi])
				break;
		}
		len = mi - postfirst;
		TreeNode *root = new TreeNode(preorder[prefirst]);
		root->left = recursive(preorder, prefirst + 1, prefirst + 2 + len, postorder, postfirst, mi + 1);
		root->right = recursive(preorder, prefirst + 2 + len, prelast, postorder, mi + 1, postlast - 1);
		return root;
	}
};