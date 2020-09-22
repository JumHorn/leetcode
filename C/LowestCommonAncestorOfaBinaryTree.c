#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct pair
{
	struct TreeNode *node;
	bool p;
	bool q;
};

struct pair postorder(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
	struct pair res = {0, false, false};
	if (!root)
		return res;
	struct pair l = postorder(root->left, p, q);
	if (l.node)
		return l;
	struct pair r = postorder(root->right, p, q);
	if (r.node)
		return r;
	res.p = l.p || r.p || root == p;
	res.q = l.q || r.q || root == q;
	if (res.p && res.q)
		res.node = root;
	return res;
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
	return postorder(root, p, q).node;
}