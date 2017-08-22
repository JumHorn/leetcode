#include<iostream>
#include<sstream>
#include<string>
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
    stringstream ss;
    string tree2str(TreeNode* t) {
        if(t==NULL)
        {
            return "";
        }
        ss<<t->val;
        if(t->left!=NULL||t->right!=NULL)
        {
            ss<<"(";
            tree2str(t->left);
            ss<<")";
            if(t->right!=NULL)
            {
                ss<<"(";
                tree2str(t->right);
                ss<<")";
            }
        }
        return ss.str();
    }
};

int main()
{}