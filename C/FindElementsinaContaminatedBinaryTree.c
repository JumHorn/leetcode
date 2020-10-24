#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct
{
	struct TreeNode* root;
} FindElements;

FindElements* findElementsCreate(struct TreeNode* root)
{
	FindElements* res = (FindElements*)malloc(sizeof(FindElements));
	res->root = root;
	return res;
}

bool findElements(struct TreeNode* root, int target, int bit)
{
	if (!root)
		return false;
	if (bit < 0)
		return true;
	if ((target >> bit) & 1)
		return findElements(root->right, target, bit - 1);
	return findElements(root->left, target, bit - 1);
}

bool findElementsFind(FindElements* obj, int target)
{
	++target;
	int i = 30;
	while (((target >> i) & 1) == 0)
		--i;
	return findElements(obj->root, target, i - 1);
}

void findElementsFree(FindElements* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/
