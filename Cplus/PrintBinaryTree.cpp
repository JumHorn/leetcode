#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
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
    vector<vector<string> > printTree(TreeNode* root) {
		int layer=getTreeHeight(root);
		int len=pow(2,layer)-1;
		vector<vector<string> > res(layer,vector<string>(len,""));
		printTree(res,root,0,len,0);
		return res;
    }

	void printTree(vector<vector<string> >& res,TreeNode* root,int l,int r,int h)
	{
		if(root==NULL)
			return;
		int mid=(r-l)/2+l;
		res[h][mid]=to_string(root->val);
		printTree(res,root->left,l,mid,h+1);
		printTree(res,root->right,mid,r,h+1);
	}

	int getTreeHeight(TreeNode* root)
	{
		if(root==NULL)
			return 0;
		return 1+max(getTreeHeight(root->left),getTreeHeight(root->right));
	}
};
