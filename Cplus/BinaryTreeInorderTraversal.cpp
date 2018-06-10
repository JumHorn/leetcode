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
    vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res;
		TreeNode* node=root;
        while(node||!s.empty())
		{
			s.push(node);
			node=node->left;
			while(!node&&!s.empty())
			{
				node=s.top();
				s.pop();
				res.push_back(node->val);
				node=node->right;
			}
		}	
		return res;
    }
};
