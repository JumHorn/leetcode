#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void preorder(struct TreeNode* root, int layer, int* data, int* dataSize)
{
	if (!root)
		return;
	if (layer >= *dataSize)
		data[(*dataSize)++] = root->val;
	else if (root->val > data[layer])
		data[layer] = root->val;
	preorder(root->left, layer + 1, data, dataSize);
	preorder(root->right, layer + 1, data, dataSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize)
{
	static int staticRes[1000];
	*returnSize = 0;
	preorder(root, 0, staticRes, returnSize);
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	memcpy(res, staticRes, sizeof(int) * (*returnSize));
	return res;
}
