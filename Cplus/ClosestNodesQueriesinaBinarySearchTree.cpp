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
	vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
	{
		vector<int> val;
		inorder(root, val);
		vector<vector<int>> res;
		for (auto &n : queries)
		{
			int maxval = -1, minval = -1;
			auto it = lower_bound(val.begin(), val.end(), n);
			if (it != val.end())
			{
				if (*it == n)
				{
					res.push_back({n, n});
					continue;
				}
				minval = *it;
			}
			if (it != val.begin())
			{
				--it;
				maxval = *it;
			}
			res.push_back({maxval, minval});
		}
		return res;
	}

	void inorder(TreeNode *root, vector<int> &res)
	{
		if (root == nullptr)
			return;
		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
	}
};