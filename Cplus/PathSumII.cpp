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
	vector<vector<int>> pathSum(TreeNode *root, int sum)
	{
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		vector<int> instance;
		dfs(root, sum, instance, res);
		return res;
	}

	void dfs(TreeNode *root, int sum, vector<int> &instance, vector<vector<int>> &res)
	{
		if (root == nullptr)
			return;
		if (root->left == nullptr && root->right == nullptr)
		{
			if (sum == root->val)
			{
				res.push_back(instance);
				res.back().push_back(root->val);
			}
			return;
		}
		instance.push_back(root->val);
		dfs(root->left, sum - root->val, instance, res);
		dfs(root->right, sum - root->val, instance, res);
		instance.pop_back();
	}
};