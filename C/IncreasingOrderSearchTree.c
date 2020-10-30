
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void inorder(struct TreeNode *root, struct TreeNode **pre)
{
	if (!root)
		return;
	inorder(root->left, pre);
	(*pre)->right = root;
	*pre = root;
	(*pre)->left = 0;
	inorder(root->right, pre);
}

struct TreeNode *increasingBST(struct TreeNode *root)
{
	struct TreeNode dummy, *d = &dummy;
	inorder(root, &d);
	return dummy.right;
}