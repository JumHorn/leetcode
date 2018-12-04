#include<vector>
#include<complex>
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
 		vector<int> res;
		if(root==target)
		{
			allDistance(res,root,K,target->val);
			return res;
		}
        if(K==0)
        {
            res.push_back(target->val);
            return res;
        }
		int d=targetDistance(root,target,0);
		if(d==K)
			res.push_back(root->val);
		allDistance(res,target,K,target->val);
		allDistance(res,root,abs(d-K),target->val);
		return res;
    }

	int targetDistance(TreeNode* root,TreeNode* target,int k)
	{
		if(root==NULL)
			return 0;
		if(root==target)
			return k;
		int tmp=targetDistance(root->left,target,k+1);
		if(tmp==0)
			tmp=targetDistance(root->right,target,k+1);
		return tmp;
	}

	void allDistance(vector<int>& v,TreeNode* root,int k,int targetval)
	{
		if(root==NULL)
			return;
		if(k==0&&root->val!=targetval)
		{
			v.push_back(root->val);
			return;
		}
		allDistance(v,root->left,k-1,targetval);
		allDistance(v,root->right,k-1,targetval);
	}
};
