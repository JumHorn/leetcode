#include<iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}  //成员初始化列表 
 };

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if(t2==NULL)
        {
        }      
        else if(t1==NULL)
        {
            t1=t2;
        }
        else
        {
            t1->val+=t2->val;
            if(t1->left==NULL)
            {
                t1->left=t2->left;
            }
            else 
            mergeTrees(t1->left,t2->left);
            if(t1->right==NULL)
            {
                t1->right=t2->right;
            }
            else
            mergeTrees(t1->right,t2->right);
        }
        return t1;
    }
};

int main()
{}
 
