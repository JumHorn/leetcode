#include<stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2){
	if(root1==NULL&&root2==NULL)
		return true;
	if(root1==NULL||root2==NULL)
		return false;
	if(root1->val!=root2->val)
		return false;
	return (flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right))
		||(flipEquiv(root1->right,root2->left)&&flipEquiv(root1->left,root2->right));
}


