
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
	{
		if (original == nullptr)
			return nullptr;
		if (original == target)
			return cloned;
		TreeNode *res = getTargetCopy(original->left, cloned->left, target);
		if (res != nullptr)
			return res;
		res = getTargetCopy(original->right, cloned->right, target);
		return res;
	}
};