#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int res;
public:
    int minDiffInBST(TreeNode* root) {
		res=INT_MAX;
		int pre=INT_MIN;
		if(root==NULL)
			return res;
		return minDiffInBST(root,pre);
    }

	int minDiffInBST(TreeNode* root,int& pre)
	{
		if(root->left!=NULL)
			minDiffInBST(root->left,pre);
		if(pre>INT_MIN)
			res=min(res,root->val-pre);
		pre=root->val;
		if(root->right!=NULL)
			minDiffInBST(root->right,pre);
		return res;
	}
};
