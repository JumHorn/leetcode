#include <algorithm>
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
	int amountOfTime(TreeNode *root, int start)
	{
		int res = 0;
		postorder(root, start, res);
		return max(0, res - 1);
	}

	//depth,parent of start
	pair<int, bool> postorder(TreeNode *root, int start, int &res)
	{
		if (root == nullptr)
			return {0, false};
		auto l = postorder(root->left, start, res);
		auto r = postorder(root->right, start, res);
		if (root->val == start)
		{
			res = max({res, l.first + 1, r.first + 1});
			return {0, true};
		}
		if (!l.second && !r.second)
			return {max(l.first, r.first) + 1, false};
		if (l.second)
		{
			res = max(res, r.first + l.first + 2);
			return {l.first + 1, true};
		}
		//r.second is true
		res = max(res, l.first + r.first + 2);
		return {r.first + 1, true};
	}
};