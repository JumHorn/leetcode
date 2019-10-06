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

struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize){
	if(preSize==0)
		return NULL;
	struct TreeNode* root=createNode(*pre);
	if(preSize==1)
		return root;
	int i=0;
	for(i=0;i<postSize;i++)
		if(pre[1]==post[i])
			break;
	root->left=constructFromPrePost(pre+1,i+1,post,i+1);
	root->right=constructFromPrePost(pre+2+i,preSize-i-2,post+i+1,postSize-i-2);
	return root;
}

