#include <stdlib.h>

// Definition for a binary tree node.
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

struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return NULL;
	int maxindex = 0;
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[maxindex] < nums[i])
			maxindex = i;
	}
	struct TreeNode *root = createNode(nums[maxindex]);
	root->left = constructMaximumBinaryTree(nums, maxindex);
	root->right = constructMaximumBinaryTree(nums + maxindex + 1, numsSize - maxindex - 1);
	return root;
}