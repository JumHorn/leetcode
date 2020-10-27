
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
	bool isSubtree(TreeNode *s, TreeNode *t)
	{
		if (s == nullptr)
			return t == nullptr;
		if (equalTree(s, t))
			return true;
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}

	bool equalTree(TreeNode *s, TreeNode *t)
	{
		if (s == nullptr && t == nullptr)
			return true;
		if (s == nullptr || t == nullptr)
			return false;
		return s->val == t->val && equalTree(s->left, t->left) && equalTree(s->right, t->right);
	}
};