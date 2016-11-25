//definition for a binary tree node
#include<stdio.h>
struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
};
void swap(struct TreeNode **p,struct TreeNode **q);
int main()
{
	struct TreeNode * invertTree(struct TreeNode * root);
}
struct TreeNode * invertTree(struct TreeNode * root)
{
	if(root==NULL)return root;
	if(root->left!=NULL&&root->right!=NULL)
	{
		swap(&root->left,&root->right);
		invertTree(root->left);
		invertTree(root->right);
	}
	if(root->left==NULL&&root->right!=NULL)
	{
		root->left=root->right;
		root->right=NULL;
		invertTree(root->left);
	}
	else if(root->left!=NULL&&root->right==NULL)
	{
		root->right=root->left;
		root->left=NULL;
		invertTree(root->right);
	}
	return root;
}

void swap(struct TreeNode **p,struct TreeNode **q)
{
	struct TreeNode * temp;

	temp=*p;
	*p=*q;
	*q=temp;
}

