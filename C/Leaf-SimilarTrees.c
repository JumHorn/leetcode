#include <stdbool.h>

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
	if (root->left == root->right)
		arr[(*arrSize)++] = root->val;
	preorder(root->left, arr, arrSize);
	preorder(root->right, arr, arrSize);
}

bool arrayEqual(int* arr1, int* arr2, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
	int arr1[1000], arr1Size = 0, arr2[1000], arr2Size = 0;
	preorder(root1, arr1, &arr1Size);
	preorder(root2, arr2, &arr2Size);
	return arr1Size == arr2Size && arrayEqual(arr1, arr2, arr1Size);
}
