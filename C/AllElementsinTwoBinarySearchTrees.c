#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void preorder(struct TreeNode* root, int* arr, int* arrSize)
{
	if (!root)
		return;
	preorder(root->left, arr, arrSize);
	arr[(*arrSize)++] = root->val;
	preorder(root->right, arr, arrSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize)
{
	int arr1[5001], arr1Size = 0, arr2[5001], arr2Size = 0;
	preorder(root1, arr1, &arr1Size);
	preorder(root2, arr2, &arr2Size);
	*returnSize = arr1Size + arr2Size;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int i = 0, j = 0, index = 0;
	while (i < arr1Size && j < arr2Size)
	{
		if (arr1[i] <= arr2[j])
			res[index++] = arr1[i++];
		else
			res[index++] = arr2[j++];
	}
	while (i < arr1Size)
		res[index++] = arr1[i++];
	while (j < arr2Size)
		res[index++] = arr2[j++];
	return res;
}
