#include <stdbool.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* preorder(struct TreeNode* root, bool parentDeleted, int* deletes, struct TreeNode** forest, int* forestSize)
{
	if (!root)
		return NULL;
	if (deletes[root->val] == 0)
	{
		if (parentDeleted)
			forest[(*forestSize)++] = root;
		parentDeleted = false;
	}
	else
		parentDeleted = true;
	root->left = preorder(root->left, parentDeleted, deletes, forest, forestSize);
	root->right = preorder(root->right, parentDeleted, deletes, forest, forestSize);
	return parentDeleted ? NULL : root;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize)
{
	int hash[1001] = {0};
	for (int i = 0; i < to_deleteSize; ++i)
		hash[to_delete[i]] = 1;
	struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
	*returnSize = 0;
	preorder(root, true, hash, res, returnSize);
	return res;
}
