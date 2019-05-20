#include<iostream>
#include<vector>
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
    void recoverTree(TreeNode* root) {
		TreeNode* pre=new TreeNode(INT_MIN);
		vector<TreeNode*> v(2);
		int tmp=0;
		recoverTree(root,v,tmp,pre);
		tmp=v[0]->val;
		v[0]->val=v[1]->val;
		v[1]->val=tmp;
    }

	void recoverTree(TreeNode* root,vector<TreeNode*>& v,int& i,TreeNode*& pre)
	{
		if(root==NULL||i>=2)
			return;
		recoverTree(root->left,v,i,pre);
		if(pre->val>root->val)
		{
			if(i==0)
			{
				v[0]=pre;
				v[1]=root;
			}
			else if(i==1)
			{
				v[1]=root;
			}
            i++;
		}
        pre=root;
		recoverTree(root->right,v,i,pre);
	}
};
