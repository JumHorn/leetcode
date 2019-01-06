#include<vector>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
		zigzagLevelOrder(root,res,0);
		for(int i=1;i<(int)res.size();i+=2)
			reverse(res[i].begin(),res[i].end());
		return res;
    }
	void zigzagLevelOrder(TreeNode* root,vector<vector<int> >& res,unsigned int layer)
	{
		if(root==NULL)
			return;
		if(layer==res.size())
			res.emplace_back();
		res[layer].push_back(root->val);
		zigzagLevelOrder(root->left,res,layer+1);
		zigzagLevelOrder(root->right,res,layer+1);
	}
};
