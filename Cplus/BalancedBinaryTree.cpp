#include<iostream>
#include<cmath>
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
    bool isBalanced(TreeNode* root) {
       if(!root)
       {
           return true;
       } 
       else 
       {
           if(!root->left&&!root->right)
           {
               return true;
           }
           else if(root->left&&root->right)
           {
               return (abs(getdepth(root->left)-getdepth(root->right))<2)&&isBalanced(root->left)&&isBalanced(root->right);
           }
           else
           {
               if(root->left)
               {
                   return !root->left->left&&!root->left->right;
               }
               else
               {
                   return !root->right->left&&!root->right->right;
               }
           }
       }
    }
    int getdepth(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        return 1+ max(getdepth(root->left),getdepth(root->right));
    }
};