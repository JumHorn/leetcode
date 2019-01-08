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
    void flatten(TreeNode* root) {
  		if(root==NULL)
	  		return;
		straight(root);		
    }

	TreeNode* straight(TreeNode* root)
	{
		if(root==NULL)
			return NULL;
		else if(root->left==NULL)
		{
			root->right=straight(root->right);
			return root;
		}
		else if(root->right==NULL)
		{
			root->right=straight(root->left);
			root->left=NULL;
			return root;
		}
		else
		{
			TreeNode* right=root->right;
			root->right=straight(root->left);
			root->left=NULL;
			TreeNode* tmp=root;
			while(tmp->right!=NULL)tmp=tmp->right;
			tmp->right=straight(right);
			return root;
		}
	}
};
