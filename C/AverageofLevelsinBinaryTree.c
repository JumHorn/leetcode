#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void preorder(struct TreeNode* root, int layer, double (*arr)[2], int* arrSize)
{
	if (!root)
		return;
	if (layer >= *arrSize)
		++*arrSize;
	arr[layer][0] += root->val;
	++arr[layer][1];
	preorder(root->left, layer + 1, arr, arrSize);
	preorder(root->right, layer + 1, arr, arrSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
	double arr[1000][2] = {{0}};  //{sum of level,node count of level}
	*returnSize = 0;
	preorder(root, 0, arr, returnSize);
	double* res = (double*)malloc(sizeof(double) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = arr[i][0] / arr[i][1];
	return res;
}
