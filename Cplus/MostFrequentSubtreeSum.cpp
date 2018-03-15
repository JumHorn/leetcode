#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
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
    map<int,int> frequence;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        int maxfreq=0;
        nodesum(root);
        for(map<int,int>::iterator iter=frequence.begin();iter!=frequence.end();iter++)
        {
            if(iter->second>maxfreq)
            {
                maxfreq=iter->second;
            }
        }
        for(map<int,int>::iterator iter=frequence.begin();iter!=frequence.end();iter++)
        {
            if(iter->second==maxfreq)
            {
                result.push_back(iter->first);
            }
        }        
        return result;
    }

    void nodesum(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        nodesum(root->left);
        nodesum(root->right);

        root->val+=(root->left?root->left->val:0)+(root->right?root->right->val:0);
        if(frequence.count(root->val)==0)
        {
            frequence[root->val]=1;
        }
        else
        {
            frequence[root->val]++;
        }
    }
};