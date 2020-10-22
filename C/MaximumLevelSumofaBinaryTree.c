#include <limits.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void preorder(struct TreeNode *root, int layer, int *arr, int *arrSize)
{
	if (!root)
		return;
	arr[layer] += root->val;
	if (layer >= *arrSize)
		*arrSize = layer + 1;
	preorder(root->left, layer + 1, arr, arrSize);
	preorder(root->right, layer + 1, arr, arrSize);
}

int maxLevelSum(struct TreeNode *root)
{
	int arr[100] = {0}, arrSize = 0;
	preorder(root, 0, arr, &arrSize);
	int res = 0;
	for (int i = 1; i < arrSize; ++i)
	{
		if (arr[i] > arr[res])
			res = i;
	}
	return res + 1;
}