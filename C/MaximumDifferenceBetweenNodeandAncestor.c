#include <limits.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct pair
{
	int big;
	int small;
} pair;

pair postorder(struct TreeNode *root, int *diff)
{
	if (!root)
	{
		pair res = {INT_MIN, INT_MAX};
		return res;
	}
	pair l = postorder(root->left, diff);
	pair r = postorder(root->right, diff);
	pair res = {max(l.big, r.big), min(l.small, r.small)};
	if (res.big >= res.small)
		*diff = max(*diff, abs(res.big - root->val));
	if (res.big >= res.small)
		*diff = max(*diff, abs(res.small - root->val));
	res.big = max(res.big, root->val);
	res.small = min(res.small, root->val);
	return res;
}

int maxAncestorDiff(struct TreeNode *root)
{
	int res = 0;
	postorder(root, &res);
	return res;
}