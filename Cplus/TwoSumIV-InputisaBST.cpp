#include<iostream>
#include<vector>
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
    vector<int> treevec;
    bool findTarget(TreeNode* root, int k) {
        TreetoVector(root);
        for(int i=0;i<treevec.size()-1;i++)
        {
            for(int j=i+1;j<treevec.size();j++)
            {
                if(treevec[i]+treevec[j]>k)
                {
                    break;
                }
                if(treevec[i]+treevec[j]==k)
                {
                    return true;
                }
            }
        }
        return false;
    }
    void TreetoVector(TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        TreetoVector(root->left);
        treevec.push_back(root->val);
        TreetoVector(root->right);
    }
       
};

int main()
{}