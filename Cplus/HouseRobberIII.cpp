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
    int rob(TreeNode* root) {
    	if(root==NULL)
		{
			return 0;
		}
		int tmp1=root->val;
		int tmp2=0;
		if(root->left!=NULL)
		{
			tmp1+=rob(root->left->left)+rob(root->left->right);
			tmp2+=rob(root->left);
		}
		if(root->right!=NULL)
		{
			tmp1+=rob(root->right->left)+rob(root->right->right);
			tmp2+=rob(root->right);
		}
		return max(tmp1,tmp2);
    }
};
