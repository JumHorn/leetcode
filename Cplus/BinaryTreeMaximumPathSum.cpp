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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
		maxPathSum(root,res);
		return res;
    }

	int maxPathSum(TreeNode* root,int& res)
	{
		if(root==NULL)
			return 0;
		res=max(res,root->val);
		int leftmaxv=maxPathSum(root->left,res);
		int rightmaxv=maxPathSum(root->right,res);
		res=max(res,leftmaxv+rightmaxv+root->val);
		root->val=max(root->val,max(leftmaxv,rightmaxv)+root->val);
		res=max(res,root->val);
		return root->val;
	}
};
