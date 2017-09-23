#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
		vector<vector<int> > result;
		queue<TreeNode*> traval;
		if(root == NULL)
		{
			return result; 
		}
		traval.push(root);
		int len;
		TreeNode *node;
		do
		{
			len = traval.size();
			vector<int> temp; 
			for(int i=0;i<len;i++)
			{
				node = traval.front();
				temp.push_back(node->val);
				traval.pop();
				if(node->left)
				{
					traval.push(node->left);
				}
				if(node->right)
				{
					traval.push(node->right);
				}
			}
			result.push_back(temp);
		}while(!traval.empty());
		//reverse(result.begin(),result.end());
	return result;
    }
};
