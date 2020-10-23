#include <stdbool.h>
#include <stdlib.h>

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
	bool isBalanced;
	int height;
} pair;

pair postorder(struct TreeNode *root)
{
	pair res = {true, 0};
	if (!root)
		return res;
	pair l = postorder(root->left);
	if (!l.isBalanced)
		return l;
	pair r = postorder(root->right);
	if (!r.isBalanced)
		return r;
	res.isBalanced = abs(l.height - r.height) <= 1;
	res.height = max(l.height, r.height) + 1;
	return res;
}

bool isBalanced(struct TreeNode *root)
{
	return postorder(root).isBalanced;
}
