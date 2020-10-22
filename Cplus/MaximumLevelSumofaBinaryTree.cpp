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
	int maxLevelSum(TreeNode *root)
	{
		vector<int> sum;
		preorder(root, 0, sum);
		int res = 0;
		for (int i = 1; i < sum.size(); ++i)
		{
			if (sum[i] > sum[res])
				res = i;
		}
		return res + 1;
	}

	void preorder(TreeNode *root, int layer, vector<int> &sum)
	{
		if (!root)
			return;
		if (layer >= (int)sum.size())
			sum.push_back(0);
		sum[layer] += root->val;
		preorder(root->left, layer + 1, sum);
		preorder(root->right, layer + 1, sum);
	}
};