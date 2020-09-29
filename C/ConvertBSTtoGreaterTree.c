
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void reverseInorder(struct TreeNode *root, int *sum)
{
	if (!root)
		return;
	reverseInorder(root->right, sum);
	root->val += *sum;
	*sum = root->val;
	reverseInorder(root->left, sum);
}

struct TreeNode *convertBST(struct TreeNode *root)
{
	int sum = 0;
	reverseInorder(root, &sum);
	return root;
}