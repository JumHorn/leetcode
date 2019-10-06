#include<stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val)
{
	struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val=val;
	node->left=NULL;
	node->right=NULL;
	return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
	if(postorderSize==0)
		return NULL;
	struct TreeNode* root=createNode(postorder[postorderSize-1]);
	if(postorderSize==1)
		return root;
	int i;
	for(i=0;i<inorderSize;i++)
		if(postorder[postorderSize-1]==inorder[i])
			break;
	root->left=buildTree(inorder,i,postorder,i);
	root->right=buildTree(inorder+i+1,inorderSize-i-1,postorder+i,postorderSize-i-1);
	return root;
}

