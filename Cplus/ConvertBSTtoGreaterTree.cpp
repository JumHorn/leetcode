#include<iostream>
#include<map>
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
    map<int,int> treemap;
    int i;
    TreeNode* convertBST(TreeNode* root) {
        i=0;
        TreetoMap(root);
        for(int j=treemap.size()-1;j>0;j--)
        {
            treemap[j-1]+=treemap[j];
        }
        i=0;
        MaptoTree(root);
        return root;
    }
    void TreetoMap(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        TreetoMap(root->left);
        treemap[i++]=root->val;
        TreetoMap(root->right);
    }
    void MaptoTree(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        MaptoTree(root->left);
        root->val=treemap[i++];
        MaptoTree(root->right);
    }
};

int main()
{}