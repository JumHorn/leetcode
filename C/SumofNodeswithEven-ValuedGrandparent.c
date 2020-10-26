
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct tuple
{
	int child;
	int grandchild;
	int res;
} tuple;

tuple postorder(struct TreeNode *root)
{
	tuple res = {0, 0, 0};
	if (!root)
		return res;
	tuple l = postorder(root->left);
	tuple r = postorder(root->right);
	res.res = l.res + r.res;
	if (root->val % 2 == 0)
		res.res += l.grandchild + r.grandchild;
	res.child = root->val;
	res.grandchild = l.child + r.child;
	return res;
}

int sumEvenGrandparent(struct TreeNode *root)
{
	return postorder(root).res;
}
