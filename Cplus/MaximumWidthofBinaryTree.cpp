#include<vector>
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
public:
    int widthOfBinaryTree(TreeNode* root) {
		if(root==NULL)
			return 0;
		if(root->left==NULL)
		{
			int tmp=widthOfBinaryTree(root->right);
			return tmp>1?tmp:1;
		}
		if(root->right==NULL)
		{
			int tmp=widthOfBinaryTree(root->left);
			return tmp>1?tmp:1;
		}
		int res=1;
		vector<int> layer;
		encode(root,0,0);
		calcuWidth(root,layer,0,res);
		return res;
    }
	
	void calcuWidth(TreeNode* root,vector<int>& layer,int level,int& res)
	{
		if(root==NULL)
			return;
		if(level==(int)layer.size())
			layer.push_back(root->val);
		else
			res=max(res,root->val-layer[level]+1);
		calcuWidth(root->left,layer,level+1,res);
		calcuWidth(root->right,layer,level+1,res);
	}

	void encode(TreeNode* root,int num,int leftright)
	{
		if(root==NULL)
			return;
		root->val=num*2+leftright;
		encode(root->left,root->val,0);
		encode(root->right,root->val,1);
	}
};
