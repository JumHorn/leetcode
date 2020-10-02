#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

bool isSameTree(struct TreeNode* lhs, struct TreeNode* rhs)
{
	if (!lhs && !rhs)
		return true;
	if (lhs && rhs)
		return lhs->val == rhs->val && isSameTree(lhs->left, rhs->left) && isSameTree(lhs->right, rhs->right);
	return false;
}

void preorder(struct TreeNode* root, struct TreeNode** nodes, int* nodesize)
{
	if (!root)
		return;
	nodes[(*nodesize)++] = root;
	preorder(root->left, nodes, nodesize);
	preorder(root->right, nodes, nodesize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize)
{
	struct TreeNode* nodes[10001];
	int nodesize = 0;
	preorder(root, nodes, &nodesize);
	struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * nodesize / 2);
	*returnSize = 0;
	for (int i = 0; i < nodesize - 1; ++i)
	{
		int index = i + 1, count = 0;
		for (int j = i + 1; j < nodesize; ++j)
		{
			if (isSameTree(nodes[i], nodes[j]))
			{
				if (++count == 1)
					res[(*returnSize)++] = nodes[i];
			}
			else
				nodes[index++] = nodes[j];
		}
		nodesize = index;
	}
	return res;
}
