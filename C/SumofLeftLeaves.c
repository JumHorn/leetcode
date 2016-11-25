#include<stdio.h>
//definition for a binary tree node
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int main()
{
	int sumOfLeftLeaves(struct TreeNode * root);
}

int sumOfLeftLeaves(struct TreeNode * root)
{
	static int sum=0;
	if(root==NULL)
	{
		return 0;
	}
	else if(root->left!=NULL)
	{
		sum+= root->left->val;
	}
	sumOfLeftLeaves(root->left);
	sumOfLeftLeaves(root->right);
	return sum;
}
