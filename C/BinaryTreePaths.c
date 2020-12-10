#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//malloc result
char **mallocRes(char (*data)[100], int dataSize, int *returnSize)
{
	*returnSize = dataSize;
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = strdup(data[i]);
	return res;
}

void addOneResult(char (*staticRes)[100], int *size, char *instance)
{
	strcpy(staticRes[(*size)++], instance);
}

void preorder(struct TreeNode *root, char *instance, int instanceSize, char (*staticRes)[100], int *size)
{
	if (!root)
		return;
	char number[20];
	if (instanceSize == 0)
		sprintf(number, "%d", root->val);
	else
		sprintf(number, "->%d", root->val);
	strcpy(&instance[instanceSize], number);
	if (root->left == root->right)
	{
		addOneResult(staticRes, size, instance);
		return;
	}
	instanceSize += strlen(number);
	preorder(root->left, instance, instanceSize, staticRes, size);
	preorder(root->right, instance, instanceSize, staticRes, size);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{
	static char staticRes[1000][100];
	char instance[100] = {0};
	*returnSize = 0;
	preorder(root, instance, 0, staticRes, returnSize);
	return mallocRes(staticRes, *returnSize, returnSize);
}