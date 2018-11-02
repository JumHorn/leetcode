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
    vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		findMostRight(res,root,0);
		return res;		
    }

	void findMostRight(vector<int>& res,TreeNode* root,int depth)
	{
		if(root==NULL)
			return;
		if(depth==res.size())
		{
			res.push_back(root->val);
		}
		findMostRight(res,root->right,depth+1);
		findMostRight(res,root->left,depth+1);
	}
};
