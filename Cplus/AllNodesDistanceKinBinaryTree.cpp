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
	TreeNode* head;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
 		vector<int> res;
		head=root;
		allDistance(res,root,target,K);
		return res;
    }

	int targetDistance(TreeNode* root,TreeNode* target,int k)
	{
		if(root==NULL)
			return -1;
		if(root==target)
			return k;
		int tmp=targetDistance(root->left,target,k+1);
		if(tmp==-1)
			tmp=targetDistance(root->right,target,k+1);
		return tmp;
	}

	int getDistance(TreeNode* root,TreeNode* node1,TreeNode* node2)
	{
		if(root==node1)
			return targetDistance(node1,node2,0);
		if(root==node2)
			return targetDistance(node2,node1,0);
		int l=targetDistance(root->left,node1,1),r=targetDistance(root->right,node2,1);
		if(l>0&&r>0)
		{
			return l+r;
		}
		else if(l>0&&r<0)
		{
			return getDistance(root->left,node1,node2);
		}
		else if(l<0&&r>0)
		{
			return getDistance(root->right,node1,node2);
		}
		else
		{
			return targetDistance(root->left,node2,1)+targetDistance(root->right,node1,1);
		}
	}

	void allDistance(vector<int>& v,TreeNode* root,TreeNode* target,int k)
	{
		if(root==NULL)
			return;
        int tmp=getDistance(head,root,target);
		if(tmp==k)
		{
			v.push_back(root->val);
		}
		allDistance(v,root->left,target,k);
		allDistance(v,root->right,target,k);
	}
};
