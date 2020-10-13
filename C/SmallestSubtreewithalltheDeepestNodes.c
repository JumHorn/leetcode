#include <stdbool.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct pair
{
	struct TreeNode *root;
	bool deepest;
} pair;

int height(struct TreeNode *root)
{
	if (!root)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

pair postorder(struct TreeNode *root, int layer)
{
	pair res = {0, false};
	if (!root)
		return res;
	if (layer == 1)
	{
		res.root = root;
		res.deepest = true;
		return res;
	}
	pair l = postorder(root->left, layer - 1);
	pair r = postorder(root->right, layer - 1);
	if (l.deepest || r.deepest)
		res.deepest = true;
	if (l.deepest && r.deepest)
		res.root = root;
	else
		res.root = l.deepest ? l.root : r.root;
	return res;
}

struct TreeNode *subtreeWithAllDeepest(struct TreeNode *root)
{
	int h = height(root);
	return postorder(root, h).root;
}