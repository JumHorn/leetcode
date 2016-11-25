#include<stdio.h>
#include<stdbool.h>
//definition for a binary tree node
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int main()
{
	bool isSymmetric(struct TreeNode *root);
}

bool isSameTree(struct TreeNode *l,struct TreeNode *r)
{
	if(l==NULL&&r==NULL)
		return true;
	if(l==NULL||r==NULL)
		return false;
	if(l->val==r->val)
		return isSameTree(l->left,r->right)&&isSameTree(l->right,r->left);
	else
		return false;
}

bool isSymmetric(struct TreeNode *root)
{
	if(root==NULL)
		return true;
	return isSameTree(root->left,root->right);
}
