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

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
	if (numsSize == 0)
		return NULL;
	struct TreeNode *root = createNode(nums[numsSize / 2]);
	root->left = sortedArrayToBST(nums, numsSize / 2);
	root->right = sortedArrayToBST(nums + numsSize / 2 + 1, numsSize - (numsSize / 2 + 1));
	return root;
}