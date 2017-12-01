#include<iostream>
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
    int result;
    int nodeval;
    int longestUnivaluePath(TreeNode* root) {
        result=0;
        traversal(root);
        return result;
    }
    void traversal(TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        int temp=getsum(root);
        if(temp>result)
        {
            result=temp;
        }
        traversal(root->left);
        traversal(root->right);
    }
    int getsum(TreeNode* root)
    {
        nodeval=root->val;
        return getmax(root->left)+getmax(root->right);
    }
    int getmax(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        if(root->val!=nodeval)
        {
            return 0;
        }
        int leftsum=getmax(root->left);
        int rightsum=getmax(root->right);
        if(leftsum>rightsum)
        {
            return leftsum+1;
        }
        else 
        {
            return rightsum+1;
        }
    }
};