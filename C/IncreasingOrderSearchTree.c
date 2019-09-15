#include<stdlib.h>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderTraversal(struct TreeNode* root,struct TreeNode** dump)
{
	if(!root)
		return;
	inorderTraversal(root->left,dump);
	(*dump)->right=(struct TreeNode*)calloc(1,sizeof(struct TreeNode));
	(*dump)=(*dump)->right;
	(*dump)->val=root->val;
	inorderTraversal(root->right,dump);
}

struct TreeNode* increasingBST(struct TreeNode* root){
	if(!root)
		return NULL;
	struct TreeNode* dump=(struct TreeNode*)calloc(1,sizeof(struct TreeNode)),*tmp=dump;
	inorderTraversal(root,&tmp);
	return dump->right;
}