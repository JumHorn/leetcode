#include<stdio.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isUnivalTree(struct TreeNode* root){
	if(root==NULL)
		return true;
	if(root->left!=NULL)
	{
		if(root->val!=root->left->val)
			return false;
		if(!isUnivalTree(root->left))
			return false;
	}
	if(root->right!=NULL)
	{
		if(root->val!=root->right->val)
			return false;
		if(!isUnivalTree(root->right))
			return false;
	}
	return true;
}

