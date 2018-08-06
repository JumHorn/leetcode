#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
    	stack<TreeNode*> s;
		while(!s.empty()||root!=NULL)
		{
			s.push(root);
			res.push_back(root->val);
			root=root->left;

			while(root==NULL&&!s.empty())
			{
				root=s.top();
				root=root->right;
				s.pop();
			}
		}
		return res;
    }
};
