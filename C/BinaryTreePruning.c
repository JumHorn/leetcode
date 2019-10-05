#include<stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkNode(struct TreeNode* root)
{
	if(root==NULL)
		return 0;
	return checkNode(root->left)+checkNode(root->right)+root->val;
}

struct TreeNode* pruneTree(struct TreeNode* root){
	if(checkNode(root)==0)
		return NULL;
	root->left=pruneTree(root->left);
	root->right=pruneTree(root->right);
	return root;
}

