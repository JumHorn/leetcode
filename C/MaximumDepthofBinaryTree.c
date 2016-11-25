#include<stdio.h>
//definition for a binary tree
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int findDepth(struct TreeNode * root);
int main()
{
	int maxDepth(struct TreeNode * root);
}

int maxDepth(struct TreeNode * root)
{
	if(root!=NULL)root->val=1;
	else return 0;
	return findDepth(root);
}

int findDepth(struct TreeNode * root)
{
	static int depth=1;
	if(root->left!=NULL)
	{
		root->left->val=root->val+1;
		if(root->left->val>depth)depth=root->left->val;
		findDepth(root->left);
	}
	if(root->right!=NULL)
	{
		root->right->val=root->val+1;
		if(root->right->val>depth)depth=root->right->val;
		findDepth(root->right);
	}
	return depth;
}
