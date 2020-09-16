#include <stdlib.h>
#include <string.h>

//Definition for a binary tree node.
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

struct TreeNode **createNodeArrary(struct TreeNode **res, int size)
{
	res = (struct TreeNode **)realloc(res, sizeof(struct TreeNode *) * size);
	return res;
}

struct TreeNode **recursive(int first, int last, int *size) //[first,last] closed range
{
	if (first > last)
	{
		*size = 1;
		struct TreeNode **res = createNodeArrary(NULL, 1);
		res[0] = NULL;
		return res;
	}
	struct TreeNode **res = NULL;
	for (int i = first; i <= last; ++i)
	{
		int leftsize = 0, rightsize = 0;
		struct TreeNode **left = recursive(first, i - 1, &leftsize);
		struct TreeNode **right = recursive(i + 1, last, &rightsize);
		res = createNodeArrary(res, *size + leftsize * rightsize);
		for (int l = 0; l < leftsize; ++l)
		{
			for (int r = 0; r < rightsize; ++r)
			{
				struct TreeNode *root = createNode(i);
				root->left = left[l];
				root->right = right[r];
				res[*size + l * rightsize + r] = root;
			}
		}
		*size += leftsize * rightsize;
	}
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode **generateTrees(int n, int *returnSize)
{
	*returnSize = 0;
	if (n == 0)
		return NULL;
	return recursive(1, n, returnSize);
}