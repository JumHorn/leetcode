#include <stdbool.h>
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
	bool flag;
	int dist;
} pair;

void preorder(struct TreeNode *root, int K, int *nodes, int *size)
{
	if (!root || K < 0)
		return;
	if (K == 0)
	{
		nodes[(*size)++] = root->val;
		return;
	}
	preorder(root->left, K - 1, nodes, size);
	preorder(root->right, K - 1, nodes, size);
}

pair postorder(struct TreeNode *root, struct TreeNode *target, int K, int *nodes, int *size)
{
	pair res = {false, 0};
	if (!root)
		return res;
	if (root == target)
	{
		res.dist = 1;
		res.flag = true;
		return res;
	}
	pair l = postorder(root->left, target, K, nodes, size);
	pair r = postorder(root->right, target, K, nodes, size);
	if (l.flag)
	{
		if (l.dist == K)
		{
			nodes[(*size)++] = root->val;
			l.flag = false;
		}
		else if (l.dist < K)
			preorder(root->right, K - l.dist - 1, nodes, size);
	}
	else if (r.flag)
	{
		if (r.dist == K)
		{
			nodes[(*size)++] = root->val;
			r.flag = false;
		}
		else if (r.dist < K)
			preorder(root->left, K - r.dist - 1, nodes, size);
	}
	res.flag = l.flag || r.flag;
	res.dist = 1 + (l.flag ? l.dist : r.dist);
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *distanceK(struct TreeNode *root, struct TreeNode *target, int K, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * 1000);
	*returnSize = 0;
	preorder(target, K, res, returnSize);
	postorder(root, target, K, res, returnSize);
	return res;
}