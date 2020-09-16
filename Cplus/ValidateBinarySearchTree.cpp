#include <climits>
#include <tuple>
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
	bool isValidBST(TreeNode *root)
	{
		return get<0>(postorder(root));
	}

	tuple<bool, long, long> postorder(TreeNode *root) //return {isBst,minval,maxval}
	{
		if (root == nullptr)
			return {true, INT_MAX + 1u, INT_MIN - 1u};
		auto l = postorder(root->left);
		auto r = postorder(root->right);
		if (get<0>(l) && get<0>(r))
		{
			if (root->val > get<2>(l) && root->val < get<1>(r))
				return {true, min(get<1>(l), (long)root->val), max(get<2>(r), (long)root->val)};
		}
		return {false, INT_MAX, INT_MIN};
	}
};