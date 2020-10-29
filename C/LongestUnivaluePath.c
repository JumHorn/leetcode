
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct pair
{
	int val;
	int len;
} pair;

pair postorder(struct TreeNode *root, int *longestpath)
{
	pair res = {0, 0};
	if (!root)
		return res;
	pair l = postorder(root->left, longestpath);
	pair r = postorder(root->right, longestpath);
	res.val = root->val;
	res.len = 1 + max(root->val == l.val ? l.len : 0, root->val == r.val ? r.len : 0);
	*longestpath = max(*longestpath, (root->val == l.val ? l.len : 0) + (root->val == r.val ? r.len : 0));
	return res;
}

int longestUnivaluePath(struct TreeNode *root)
{
	int res = 0;
	postorder(root, &res);
	return res;
}
