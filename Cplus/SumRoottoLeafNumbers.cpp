#include<iostream>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
		if(root==NULL)
			return 0;
 		return sumNumbers(root,0);
    }

	int sumNumbers(TreeNode* root,int n)
	{
		if(root->left==NULL&&root->right==NULL)
			return n*10+root->val;
		int n1=0,n2=0;
		if(root->left!=NULL)
			n1=sumNumbers(root->left,n*10+root->val);
		if(root->right!=NULL)
			n2=sumNumbers(root->right,n*10+root->val);
		return n1+n2;
	}
};
