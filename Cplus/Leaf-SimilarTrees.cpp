#include<iostream>
#include<vector>
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> sequence;
		getSequence(root1,sequence);
		int tmp=0;
		return judge(root2,sequence,tmp);
    }

	bool judge(TreeNode* root,vector<int>& v,int& start)
	{
		if(root==NULL)
			return start==(int)v.size();
		if(root->left==NULL&&root->right==NULL)
			if(root->val!=v[start++])
				return false;
		if(!judge(root->left,v,start))
			return false;
		if(!judge(root->right,v,start))
			return false;
		return true;
	}

	void getSequence(TreeNode* root,vector<int>& v)
	{
		if(root==NULL)
			return;
		if(root->left==NULL&&root->right==NULL)
			v.push_back(root->val);
		getSequence(root->left,v);
		getSequence(root->right,v);
	}
};
