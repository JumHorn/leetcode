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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.empty())
			return NULL;
		return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

	TreeNode* buildTree(vector<int>& preorder,int i,int j,vector<int>& inorder,int m,int n)
	{
		TreeNode* root=new TreeNode(preorder[i]);
		int k;
		for(k=m;k<n;k++)
			if(inorder[k]==preorder[i])
				break;
		if(k-m>0)
			root->left=buildTree(preorder,i+1,i+k-m,inorder,m,k-1);
		if(n-k>0)
			root->right=buildTree(preorder,i+k-m+1,j,inorder,k+1,n);
		return root;
	}
};
