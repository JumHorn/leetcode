#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* balanceBST(TreeNode* root)
	{
		vector<int> v;
		inorder(root, v);
		return buildTree(v, 0, v.size() - 1);
	}

	TreeNode* buildTree(vector<int>& v, int i, int j)
	{
		if (i > j)
			return NULL;
		int mi = (j - i) / 2 + i;
		TreeNode* root = new TreeNode(v[mi]);
		root->left = buildTree(v, i, mi - 1);
		root->right = buildTree(v, mi + 1, j);
		return root;
	}

	void inorder(TreeNode* root, vector<int>& v)
	{
		if (root == NULL)
			return;
		inorder(root->left, v);
		v.push_back(root->val);
		inorder(root->right, v);
	}
};
