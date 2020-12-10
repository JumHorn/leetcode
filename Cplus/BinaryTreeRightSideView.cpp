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
	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> res;
		flipPreorder(root, 0, res);
		return res;
	}

	void flipPreorder(TreeNode *root, int depth, vector<int> &res)
	{
		if (root == nullptr)
			return;
		if (depth == (int)res.size())
			res.push_back(root->val);
		flipPreorder(root->right, depth + 1, res);
		flipPreorder(root->left, depth + 1, res);
	}
};