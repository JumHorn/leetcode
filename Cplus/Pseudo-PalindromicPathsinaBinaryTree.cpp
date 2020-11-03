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
	int pseudoPalindromicPaths(TreeNode *root)
	{
		vector<int> v(10);
		int res = 0;
		preorder(root, v, res);
		return res;
	}

	void preorder(TreeNode *root, vector<int> &v, int &res)
	{
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
		{
			v[root->val] ^= 1;
			int sum = 0;
			for (int i = 1; i < 10; ++i)
				sum += v[i];
			if (sum < 2)
				++res;
			v[root->val] ^= 1;
			return;
		}
		v[root->val] ^= 1;
		preorder(root->left, v, res);
		preorder(root->right, v, res);
		v[root->val] ^= 1;
	}
};
