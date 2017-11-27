#include<iostream>
#include<vector>
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
    vector<int> result;
    int max,num,first;
    vector<int> findMode(TreeNode* root) {
        max=1;
        num=0;
        first=-1;
        if(!root)
        {
            return result;
        }
        BFS(root);
        if(num>max)
        {
            result.clear();
            result.push_back(first);
        }
        else if(num==max)
        {
            result.push_back(first);
        }
        else
        {
        }
        return result;
    }
    void BFS(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        BFS(root->left);
        if(root->val==first)
        {
            num++;
        }
        else
        {
            if(num>max)
            {
                result.clear();
                max=num;
                result.push_back(first);
            }
            else if(num==max)
            {
                result.push_back(first);
            }
            else
            {
            }
            num=1;
        }
        first=root->val;
        BFS(root->right);
    }
};