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

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val){
	if(!root)
		return createNode(val);
	if(root->val<=val)
	{
		struct TreeNode* res=createNode(val);
		res->left=root;
		return res;
	}
	root->right=insertIntoMaxTree(root->right,val);
	return root;
}
