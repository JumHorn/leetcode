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
    int findSecondMinimumValue(TreeNode* root) {
        int first,second = -1;
       if(!root)
       {
           return -1;
       }
       first = root->val;
       stack<TreeNode*> s;
       TreeNode* node = root;
       while(node||!s.empty())
       {
           s.push(node);
           node = node->left;
           while(!node&&!s.empty())
           {
               node = s.top();
               //InOrder processing
               if(node->val>first)
               {
                   if(second==-1)
                   {
                       second = node->val;
                   }
                   else
                   {
                       if(node->val<second)
                       {
                           second = node->val;
                       }
                   }
               }

               s.pop();
               node=node->right;
           }
       }

       return second;
   }
};