#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct pair
{
	char *str;
	struct TreeNode *node;
} pair;

//string cmp function
int cmp(const void *lhs, const void *rhs)
{
	return strcmp(((pair *)lhs)->str, ((pair *)rhs)->str);
}

char *postorder(struct TreeNode *root, pair *nodes, int *nodesize)
{
	if (!root)
		return "";
	char *left = postorder(root->left, nodes, nodesize);
	char *right = postorder(root->right, nodes, nodesize);
	int l = strlen(left), r = strlen(right);
	char *res = (char *)malloc(sizeof(char) * (l + r + 10));
	nodes[*nodesize].node = root;
	nodes[*nodesize].str = res;
	sprintf(res, "%d,%s,%s", root->val, left, right);
	++*nodesize;
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode **findDuplicateSubtrees(struct TreeNode *root, int *returnSize)
{
	pair nodes[10001];
	int nodesize = 0;
	postorder(root, nodes, &nodesize);
	qsort(nodes, nodesize, sizeof(pair), cmp);
	struct TreeNode **res = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * nodesize / 2);
	*returnSize = 0;
	for (int i = 1, j = 0; i < nodesize; i = j + 1)
	{
		while (i < nodesize && strcmp(nodes[i - 1].str, nodes[i].str) == 0)
			++i;
		if (i - j > 1)
			res[(*returnSize)++] = nodes[j].node;
		j = i;
	}
	return res;
}