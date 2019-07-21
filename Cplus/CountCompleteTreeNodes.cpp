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
    int countNodes(TreeNode* root) {
        if(root==NULL)
			return 0;
		int l=height(root->left);
		int r=height(root->right);
		if(l==r)
			return l+r+1;
		return l+r;
    }

	int height(TreeNode* root)
	{
		if(root==NULL)
			return 0;
		return max(height(root->left),height(root->right))+1;
	}

	bool complete(TreeNode* root)
	{
		if(root->left==NULL&&root->right==NULL)
			return true;
		return complete(root->left)&&complete(root->right);
	}
};
