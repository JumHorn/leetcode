#include<iostream>
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
		TreeNode* trimBST(TreeNode* root, int L, int R) {
			if(!root)
			{
				return NULL;
			}
			else
			{
				root->left=trimBST(root->left,L,R);
				root->right=trimBST(root->right,L,R);
				if(root->val>R)
				{
					return root->left;
				}
				else if(root->val<L)
				{
					return root->right;
				}	
				else
				{
					return root;
				}
			}
		}
};
