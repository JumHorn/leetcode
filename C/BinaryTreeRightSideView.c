#include <stdlib.h>
#include <string.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void reverse_preorder(struct TreeNode* root, int layer, int* res, int* size)
{
	if (!root)
		return;
	if (layer >= *size)
	{
		++*size;
		res[layer] = root->val;
	}
	reverse_preorder(root->right, layer + 1, res, size);
	reverse_preorder(root->left, layer + 1, res, size);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize)
{
	int staticRes[1000];
	*returnSize = 0;
	reverse_preorder(root, 0, staticRes, returnSize);
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	memcpy(res, staticRes, sizeof(int) * (*returnSize));
	return res;
}
