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
		vector<int> sequence1,sequence2;
		getSequence(root1,sequence1);
		getSequence(root2,sequence2);
		return sequence1==sequence2;
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
