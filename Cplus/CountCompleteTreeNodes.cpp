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
	int countNodes(TreeNode* root)
	{
		int res=0;
		countNodes(root,res);
		return res;
	}

    bool countNodes(TreeNode* root,int& res) {
        if(root==NULL)
			return true;
		bool l=countNodes(root->left,res);
		bool r=countNodes(root->right,res);
		if(l&&r)
		{
			int lh=height(root->left);
			int rh=height(root->right);
			if(lh==rh&&complete(root->left))
			{
				++res;
				return true;
			}
			if(lh-rh==1&&complete(root->right))
			{
				++res;
				return true;
			}
		}
		return false;
    }

	int height(TreeNode* root)
	{
		if(root==NULL)
			return 0;
		return max(height(root->left),height(root->right))+1;
	}

	bool complete(TreeNode* root)
	{
		if(root==NULL)
			return true;
		if(root->left!=NULL&&root->right!=NULL)
			return complete(root->left)&&complete(root->right);
		if(root->left==NULL&&root->right==NULL)
			return true;
		return false;
	}
};
