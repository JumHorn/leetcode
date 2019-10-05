#include<stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
	if(root==NULL)
	{
		root=(struct TreeNode*)calloc(1,sizeof(struct TreeNode));
		root->val=val;
		return root;
	}
	if(root->val>val)
		root->left=insertIntoBST(root->left,val);
	else
		root->right=insertIntoBST(root->right,val);
	return root;
}

