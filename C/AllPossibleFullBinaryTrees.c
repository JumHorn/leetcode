#include <stdlib.h>
#include <string.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *deepCopy(struct TreeNode *root)
{
	if (!root)
		return NULL;
	struct TreeNode *res = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	res->val = 0;
	res->left = deepCopy(root->left);
	res->right = deepCopy(root->right);
	return res;
}

void createTree(struct TreeNode ***dp, int *dpsize, int N)
{
	if (N == 0 || dp[N] != NULL)
		return;
	for (int i = 1; i < N; i += 2)
	{
		if (dp[i] == NULL)
			createTree(dp, dpsize, i);
		if (dp[N - 1 - i] == NULL)
			createTree(dp, dpsize, N - 1 - i);
		for (int j = 0; j < dpsize[i]; j++)
			for (int k = 0; k < dpsize[N - 1 - i]; k++)
			{
				struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
				node->val = 0;
				node->left = deepCopy(dp[i][j]);
				node->right = deepCopy(dp[N - 1 - i][k]);
				if (dp[N] == NULL)
				{
					dp[N] = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
					dp[N][0] = node;
				}
				else
				{
					dp[N] = (struct TreeNode **)realloc(dp[N], (dpsize[N] + 1) * sizeof(struct TreeNode *));
					dp[N][dpsize[N]] = node;
				}
				dpsize[N]++;
			}
	}
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode **allPossibleFBT(int N, int *returnSize)
{
	*returnSize = 0;
	if (N % 2 == 0)
		return NULL;
	struct TreeNode ***dp = (struct TreeNode ***)malloc((N + 1) * sizeof(struct TreeNode **));
	memset(dp, 0, (N + 1) * sizeof(struct TreeNode **));
	dp[0] = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
	dp[1] = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
	dp[0][0] = NULL;
	dp[1][0] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	dp[1][0]->val = 0;
	dp[1][0]->left = NULL;
	dp[1][0]->right = NULL;
	int *dpsize = (int *)malloc((N + 1) * sizeof(int));
	memset(dpsize, 0, (N + 1) * sizeof(int));
	dpsize[0] = dpsize[1] = 1;
	createTree(dp, dpsize, N);
	*returnSize = dpsize[N];
	return dp[N];
}