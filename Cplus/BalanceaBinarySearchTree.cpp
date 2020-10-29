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
	TreeNode *balanceBST(TreeNode *root)
	{
		vector<int> data;
		inorder(root, data);
		return buildTree(data, 0, data.size() - 1);
	}

	TreeNode *buildTree(vector<int> &data, int first, int last)
	{
		if (first > last)
			return nullptr;
		int mi = (last - first) / 2 + first;
		TreeNode *root = new TreeNode(data[mi]);
		root->left = buildTree(data, first, mi - 1);
		root->right = buildTree(data, mi + 1, last);
		return root;
	}

	void inorder(TreeNode *root, vector<int> &data)
	{
		if (root == nullptr)
			return;
		inorder(root->left, data);
		data.push_back(root->val);
		inorder(root->right, data);
	}
};