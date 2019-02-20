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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
		   return root;
		TreeNode* tmp=root;
		if(root->val==key)
		{
			insertNode(root->left,root->right);
			root=(root->left!=NULL?root->left:root->right);
			delete tmp;
			return root;
		}
		if(root->val>key)
			deleteNode(root,root,root->left,key);
		else
			deleteNode(root,root,root->right,key);
		return root;
    }
	
	void deleteNode(TreeNode* root,TreeNode* p,TreeNode* node,int key)
	{
		if(node==NULL)
			return;
		if(node->val==key)
		{
			TreeNode* left=node->left;
			TreeNode* right=node->right;
			if(p->left==node)
			{
				p->left=NULL;
				delete node;
			}
			else
			{
				p->right=NULL;
				delete node;
			}
			insertNode(root,left);
			insertNode(root,right);
		}
		else if(node->val>key)
		{
			if(node->left!=NULL)
			{
				deleteNode(root,node,node->left,key);
			}
		}
		else
		{
			if(node->right!=NULL)
			{
				deleteNode(root,node,node->right,key);
			}
		}
	}

	void insertNode(TreeNode* root,TreeNode* node)
	{
		if(root==NULL||node==NULL)
			return;
		if(root->val>node->val)
		{
			if(root->left==NULL)
				root->left=node;
			else
				insertNode(root->left,node);
		}
		else
		{
			if(root->right==NULL)
				root->right=node;
			else
				insertNode(root->right,node);
		}
	}
};
