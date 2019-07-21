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
			if(lh-rh<=1)
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
		return height(root->left)+1;
	}
};
