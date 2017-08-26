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
    int pre=2147483647;
    int min=2147483647;
    int getMinimumDifference(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        getMinimumDifference(root->left);
        if(root->val-pre<min&&root->val-pre>=0)
        {
            min=root->val-pre;
        }
        pre=root->val;
        getMinimumDifference(root->right);
        return min;
    }
};

int main()
{}