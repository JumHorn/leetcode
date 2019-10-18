#include<stdlib.h>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



int distributeCoins(struct TreeNode* root){
	if(!root)
		return 0;
	int left=distributeCoins(root->left);
	int right=distributeCoins(root->right);
	root->val-=1;
	if(root->left)
		root->val+=root->left->val;
	if(root->right)
		root->val+=root->right->val;
	return left+right+abs(root->val);
}
