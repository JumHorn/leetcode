#include<stdlib.h>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void reverseInorder(struct TreeNode* root,int* pre)
{
	if(!root)
		return;
	reverseInorder(root->right,pre);
	root->val+=*pre;
	*pre=root->val;
	reverseInorder(root->left,pre);
}

struct TreeNode* bstToGst(struct TreeNode* root)
{
	int pre=0;
	reverseInorder(root,&pre);
	return root;
}