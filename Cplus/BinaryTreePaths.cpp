#include<iostream>
#include<sstream>
#include<vector>
#include<string>
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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> result;
        vector<int> temp;
        FindTreePaths(root,result,temp);
        return result;
    }
    void FindTreePaths(TreeNode* root,vector<string>& result,vector<int>& temp) 
    {
        if(!root)
        {
            return ;
        }
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            stringstream ss;
            ss<<temp[0];
            for(vector<int>::iterator iter = temp.begin()+1;iter!=temp.end();iter++)
            {
                ss<<"->"<<*iter;
            }
            result.push_back(ss.str());
            // return result;
        }
        FindTreePaths(root->left,result,temp);
        FindTreePaths(root->right,result,temp);
        temp.pop_back();
        return ;
    }
};

class Solution0 {
public:
    vector<string> result;
    vector<int> temp;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
        {
            return result;
        }
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            stringstream ss;
            ss<<temp[0];
            for(vector<int>::iterator iter = temp.begin()+1;iter!=temp.end();iter++)
            {
                ss<<"->"<<*iter;
            }
            result.push_back(ss.str());
            // return result;
        }
        binaryTreePaths(root->left);
        binaryTreePaths(root->right);
        temp.pop_back();
        return result;
    }
};


// void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
//     if(!root->left && !root->right) {
//         result.push_back(t);
//         return;
//     }

//     if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
//     if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
// }

// vector<string> binaryTreePaths(TreeNode* root) {
//     vector<string> result;
//     if(!root) return result;
    
//     binaryTreePaths(result, root, to_string(root->val));
//     return result;
// }