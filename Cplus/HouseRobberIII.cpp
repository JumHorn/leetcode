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

//more effeciency solution
//class Solution {
//public:
//    int rob(TreeNode* root) {
//        vector<int> ans;
//        ans = subrob(root);
//        return max(ans[0], ans[1]);
//    }
//    vector<int> subrob(TreeNode* root){
//        vector<int> res;
//        if(!root){
//            res.push_back(0);
//            res.push_back(0);
//            return res;
//        }
//        vector<int> left = subrob(root->left);
//        vector<int> right = subrob(root->right);
//        int not_rubbed = max(left[0], left[1]) + max(right[0], right[1]);
//        int rubbed = root->val + left[0] + right[0];
//        res.push_back(not_rubbed);
//        res.push_back(rubbed);
//        return res;
//    }
//};
