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
	bool leafSimilar(TreeNode *root1, TreeNode *root2)
	{
		vector<int> sequence1, sequence2;
		preorder(root1, sequence1);
		preorder(root2, sequence2);
		return sequence1 == sequence2;
	}

	void preorder(TreeNode *root, vector<int> &data)
	{
		if (root == nullptr)
			return;
		if (root->left == nullptr && root->right == nullptr)
			data.push_back(root->val);
		preorder(root->left, data);
		preorder(root->right, data);
	}
};