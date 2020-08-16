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
	memset(node, 0, sizeof(struct TreeNode));
	node->val = val;
	return node;
}

int strToInt(char *S, int *index)
{
	int res = 0;
	while (S[*index] && S[*index] != '-')
	{
		res = res * 10 + S[*index] - '0';
		++*index;
	}
	return res;
}

struct TreeNode *preorder(char *S, int *index, int layer)
{
	int depth = *index;
	while (S[depth] && S[depth] == '-')
		++depth;
	depth -= *index;
	if (depth != layer)
		return NULL;
	*index += depth;
	struct TreeNode *node = createNode(strToInt(S, index));
	node->left = preorder(S, index, layer + 1);
	node->right = preorder(S, index, layer + 1);
	return node;
}

struct TreeNode *recoverFromPreorder(char *S)
{
	int index = 0;
	return preorder(S, &index, 0);
}
