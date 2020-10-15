#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
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

bool preorder(struct TreeNode *root, int layer, int val, int *res)
{
	if (!root)
		return false;
	if (layer == 0)
	{
		*res = root->val;
		if (!root->left)
		{
			root->left = createNode(val);
			return true;
		}
		if (!root->right)
		{
			root->right = createNode(val);
			return true;
		}
		return false;
	}
	if (preorder(root->left, layer - 1, val, res))
		return true;
	return preorder(root->right, layer - 1, val, res);
}

int getHeight(struct TreeNode *root)
{
	if (!root)
		return 0;
	return 1 + getHeight(root->left);
}

typedef struct
{
	struct TreeNode *root;
} CBTInserter;

CBTInserter *cBTInserterCreate(struct TreeNode *root)
{
	CBTInserter *inserter = (CBTInserter *)malloc(sizeof(CBTInserter));
	inserter->root = root;
	return inserter;
}

int cBTInserterInsert(CBTInserter *obj, int v)
{
	int height = getHeight(obj->root), res = 0;
	if (preorder(obj->root, height - 2, v, &res))
		return res;
	preorder(obj->root, height - 1, v, &res);
	return res;
}

struct TreeNode *cBTInserterGet_root(CBTInserter *obj)
{
	return obj->root;
}

void cBTInserterFree(CBTInserter *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your CBTInserter struct will be instantiated and called as such:
 * CBTInserter* obj = cBTInserterCreate(root);
 * int param_1 = cBTInserterInsert(obj, v);

 * struct TreeNode* param_2 = cBTInserterGet_root(obj);

 * cBTInserterFree(obj);
*/