#include <stdlib.h>
#include <string.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *createNode(int val, struct TreeNode *left, struct TreeNode *right)
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->left = left;
	node->right = right;
	node->val = val;
	return node;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode **allPossibleFBT(int N, int *returnSize)
{
	*returnSize = 0;
	if (N % 2 == 0)
		return NULL;
	struct TreeNode *dp[N + 1][5000];
	int dpSize[N + 1];
	memset(dpSize, 0, sizeof(dpSize));
	dp[1][dpSize[1]++] = createNode(0, NULL, NULL);
	for (int i = 3; i <= N; i += 2)
	{
		for (int j = 1; j < i; j += 2)
		{
			for (int l = 0; l < dpSize[j]; ++l)
			{
				for (int r = 0; r < dpSize[i - 1 - j]; ++r)
					dp[i][dpSize[i]++] = createNode(0, dp[j][l], dp[i - 1 - j][r]);
			}
		}
	}
	*returnSize = dpSize[N];
	struct TreeNode **res = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * (*returnSize));
	memcpy(res, dp[N], sizeof(struct TreeNode *) * (*returnSize));
	return res;
}