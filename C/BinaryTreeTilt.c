#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct pair
{
	int sum;
	int tilt;
} pair;

pair postorder(struct TreeNode *root)  //{res,sum of all node}
{
	pair res = {0, 0};
	if (!root)
		return res;
	pair l = postorder(root->left);
	pair r = postorder(root->right);
	res.sum = l.sum + r.sum + root->val;
	res.tilt = l.tilt + r.tilt + abs(l.sum - r.sum);
	return res;
}

int findTilt(struct TreeNode *root)
{
	return postorder(root).tilt;
}
