#include<iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
		return isValidBST(root,INT_MIN-1L,INT_MAX+1L);
	}

    bool isValidBST(TreeNode* root,long min,long max) {
        if(root==NULL)
			return true;
		if(root->val>=max||root->val<=min)
			return false;
		if(root->left!=NULL&&(root->left->val>=root->val||root->left->val<=min))
			return false;
		if(root->right!=NULL&&(root->right->val<=root->val||root->right->val>=max))
			return false;
		return isValidBST(root->left,min,root->val)&&isValidBST(root->right,root->val,max);
    }
};
