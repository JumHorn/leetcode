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
	int depth;
	struct TreeNode *root;
} pair;

pair postorder(struct TreeNode *root)
{
	pair res = {0, 0};
	if (!root)
		return res;
	pair l = postorder(root->left);
	pair r = postorder(root->right);
	res.depth = max(l.depth, r.depth) + 1;
	if (l.depth == r.depth)
		res.root = root;
	else
		res.root = (l.depth > r.depth) ? l.root : r.root;
	return res;
}

struct TreeNode *lcaDeepestLeaves(struct TreeNode *root)
{
	return postorder(root).root;
}