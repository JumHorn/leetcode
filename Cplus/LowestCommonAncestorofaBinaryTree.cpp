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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q)
			return root;
		if(findNode(root->left,p))
		{
			if(findNode(root->right,q))
				return root;
			return lowestCommonAncestor(root->left,p,q);
		}
		else
		{
			if(findNode(root->left,q))
				return root;
			return lowestCommonAncestor(root->right,p,q);
		}
    }

	bool findNode(TreeNode* root,TreeNode* node)
	{
        if(root==NULL)
            return false;
		if(root==node)
			return true;
		return findNode(root->left,node)||findNode(root->right,node);
	}
};
