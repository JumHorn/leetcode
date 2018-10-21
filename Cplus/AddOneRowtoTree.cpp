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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if(root==NULL)
		{
			return new TreeNode(v);
		}
		if(d==1)
		{
			TreeNode* tmp=new TreeNode(v);
			tmp->left=root;
			return tmp;
		}
		root->left=addRow(root->left,true,v,d-1);
		root->right=addRow(root->right,false,v,d-1);
		return root;
    }

	TreeNode* addRow(TreeNode* root,bool lr,int v,int d)
	{
		if(d==1)
		{
			TreeNode* tmp=new TreeNode(v);
			if(lr)
			{
				tmp->left=root;
			}
			else
			{
				tmp->right=root;
			}
			return tmp;
		}
		if(root==NULL)
		{
			return NULL;
		}
		root->left=addRow(root->left,true,v,d-1);
		root->right=addRow(root->right,false,v,d-1);
		return root;
	}
};
