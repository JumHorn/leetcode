#include<iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int level;
    int result;
    int findBottomLeftValue(TreeNode* root) {
        level=0;
        result=root->val;
        treeTraversal(root,0);
        return result;
    }

    void treeTraversal(TreeNode* root,int layer)
    {
        if(!root)
        {
            return;
        }
        if(layer>level)
        {
            result=root->val;
            level=layer;
        }
        treeTraversal(root->left,layer+1);
        treeTraversal(root->right,layer+1);
    }
};