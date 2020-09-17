
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void preorder(struct TreeNode *root, struct TreeNode **pre)
{
	if (!root)
		return;
	struct TreeNode *left = root->left;
	struct TreeNode *right = root->right;
	(*pre)->right = root;
	root->left = 0;
	(*pre) = root;
	preorder(left, pre);
	preorder(right, pre);
}

void flatten(struct TreeNode *root)
{
	struct TreeNode dummy, *d = &dummy;
	preorder(root, &d);
}
