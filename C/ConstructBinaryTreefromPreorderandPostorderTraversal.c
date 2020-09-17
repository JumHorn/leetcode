#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->left = node->right = NULL;
	node->val = val;
	return node;
}

struct TreeNode *constructFromPrePost(int *pre, int preSize, int *post, int postSize)
{
	if (preSize == 0)
		return NULL;
	struct TreeNode *root = createNode(*pre);
	if (preSize == 1)
		return root;
	int mi = 0;
	for (mi = 0; mi < postSize; ++mi)
	{
		if (pre[1] == post[mi])
			break;
	}
	root->left = constructFromPrePost(pre + 1, mi + 1, post, mi + 1);
	root->right = constructFromPrePost(pre + 2 + mi, preSize - mi - 2, post + mi + 1, postSize - mi - 2);
	return root;
}