
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct pair
{
	int height;
	int value;
} pair;

pair postorder(struct TreeNode *root)
{
	pair res = {0, 0};
	if (!root)
		return res;
	if (!root->left && !root->right)
	{
		res.value = root->val;
		return res;
	}
	pair l = postorder(root->left);
	pair r = postorder(root->right);
	res.height = 1 + (l.height < r.height ? r.height : l.height);
	if (l.height == r.height)
		res.value = l.value + r.value;
	else
		res.value = l.height < r.height ? r.value : l.value;
	return res;
}

int deepestLeavesSum(struct TreeNode *root)
{
	return postorder(root).value;
}
