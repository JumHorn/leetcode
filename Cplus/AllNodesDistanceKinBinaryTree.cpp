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
	vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
	{
		vector<int> res;
		preorder(target, K, res);
		postorder(root, target, K, res);
		return res;
	}

	pair<bool, int> postorder(TreeNode *root, TreeNode *target, int K, vector<int> &res)
	{
		if (root == nullptr)
			return {false, 0};
		if (root == target)
			return {true, 1};
		auto l = postorder(root->left, target, K, res);
		auto r = postorder(root->right, target, K, res);
		if (l.first)
		{
			if (l.second == K)
			{
				res.push_back(root->val);
				l.first = false;
			}
			else if (l.second < K)
				preorder(root->right, K - l.second - 1, res);
		}
		else if (r.first)
		{
			if (r.second == K)
			{
				res.push_back(root->val);
				r.first = false;
			}
			else if (r.second < K)
				preorder(root->left, K - r.second - 1, res);
		}
		return {l.first || r.first, 1 + (l.first ? l.second : r.second)};
	}

	void preorder(TreeNode *root, int K, vector<int> &res)
	{
		if (root == nullptr || K < 0)
			return;
		if (K == 0)
		{
			res.push_back(root->val);
			return;
		}
		preorder(root->left, K - 1, res);
		preorder(root->right, K - 1, res);
	}
};