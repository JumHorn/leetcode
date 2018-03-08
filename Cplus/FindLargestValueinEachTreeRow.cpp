#include<iostream>
#include<vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> result;
    vector<int> largestValues(TreeNode* root) {
        CompareValues(root,1);
        return result;
    }

    void CompareValues(TreeNode* node,int depth)
    {
        if(!node)
        {
            return;
        }
        //processing
        if(result.size()>=depth)
        {
            if(result[depth-1]<node->val)
            {
                result[depth-1]=node->val;
            }
        }
        else
        {
            result.push_back(node->val);
        }
        CompareValues(node->left,depth+1);
        CompareValues(node->right,depth+1);
    }
};