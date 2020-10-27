#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void preorder(struct TreeNode *root, char *res, int *resSize)
{
	if (!root)
		return;
	*resSize += sprintf(&res[*resSize], "%d", root->val);
	if (root->left)
	{
		res[(*resSize)++] = '(';
		preorder(root->left, res, resSize);
		res[(*resSize)++] = ')';
	}
	if (root->right)
	{
		if (!root->left)
			*resSize += sprintf(&res[*resSize], "()");
		res[(*resSize)++] = '(';
		preorder(root->right, res, resSize);
		res[(*resSize)++] = ')';
	}
}

char *tree2str(struct TreeNode *t)
{
	char *res = (char *)malloc(sizeof(char) * 50000);
	int resSize = 0;
	preorder(t, res, &resSize);
	res[resSize] = '\0';
	return res;
}