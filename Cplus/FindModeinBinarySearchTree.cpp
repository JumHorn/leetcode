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
	vector<int> findMode(TreeNode *root)
	{
		vector<int> res;
		int pre = 0, count = 0, maxcount = 1;
		inorder(root, pre, count, maxcount, res);
		return res;
	}

	void inorder(TreeNode *root, int &pre, int &count, int &maxcount, vector<int> &res)
	{
		if (root == nullptr)
			return;
		inorder(root->left, pre, count, maxcount, res);
		if (pre != root->val)
		{
			pre = root->val;
			count = 0;
		}
		++count;
		if (count >= maxcount)
		{
			if (count > maxcount)
			{
				maxcount = count;
				res.clear();
			}
			res.push_back(root->val);
		}
		inorder(root->right, pre, count, maxcount, res);
	}
};