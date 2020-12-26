#include <string>
#include <unordered_map>
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
	vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
	{
		unordered_map<string, int> dp; //{tree,count}
		vector<TreeNode *> res;
		preorder(root, dp, res);
		return res;
	}

	string preorder(TreeNode *root, unordered_map<string, int> &dp, vector<TreeNode *> &res)
	{
		if (root == nullptr)
			return "";
		string compressedtree = to_string(root->val) + ',' +
								preorder(root->left, dp, res) + ',' +
								preorder(root->right, dp, res);
		if (++dp[compressedtree] == 2)
			res.push_back(root);
		return compressedtree;
	}
};