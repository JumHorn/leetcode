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

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	if(preorderSize==0)
		return NULL;
	struct TreeNode* root=createNode(*preorder);
	if(preorderSize==1)
		return root;
	int i;
	for(i=0;i<inorderSize;i++)
		if(inorder[i]==*preorder)
			break;
	root->left=buildTree(preorder+1,i,inorder,i);
	root->right=buildTree(preorder+1+i,preorderSize-i-1,inorder+i+1,inorderSize-i-1);
	return root;
}

