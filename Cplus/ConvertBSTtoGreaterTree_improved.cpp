#include<iostream>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int i;
    TreeNode* convertBST(TreeNode* root) {
        i=0;
        Increase(root);
        return root;
    }
    void Increase(TreeNode* root)
    {
        if(!root)return;
        Increase(root->right);
        root->val=(i+=root->val);
        Increase(root->left);
    }
};

int main()
{}