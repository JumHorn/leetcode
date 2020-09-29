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
	vector<int> largestValues(TreeNode *root)
	{
		vector<int> res;
		preorder(root, 0, res);
		return res;
	}

	void preorder(TreeNode *root, int layer, vector<int> &res)
	{
		if (root == nullptr)
			return;
		if (layer >= (int)res.size())
			res.push_back(root->val);
		else if (root->val > res[layer])
			res[layer] = root->val;
		preorder(root->left, layer + 1, res);
		preorder(root->right, layer + 1, res);
	}
};