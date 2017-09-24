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
    int kthSmallest(TreeNode* root, int k) {
       stack<TreeNode* > s;
       TreeNode* node = root;
       while(node||!s.empty())
       {
           s.push(node);
           node=node->left;
           while(!node&&!s.empty())
           {
               node=s.top();
               //InOrder processing
               if(k==1)
               {
                   return node->val;
               }
               else
               {
                   k--;
               }
               s.pop();
               node=node->right;
           }
       } 
       return 0;
    }
};

// int count = 0;
// int result = Integer.MIN_VALUE;

// public int kthSmallest(TreeNode root, int k) {
//     traverse(root, k);
//     return result;
// }

// public void traverse(TreeNode root, int k) {
//     if(root == null) return;
//     traverse(root.left, k);
//     count ++;
//     if(count == k) result = root.val;
//     traverse(root.right, k);       
// }