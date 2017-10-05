#include<iostream>
#include<vector>
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
    int value = 0;
    TreeNode* parent;
    stack<TreeNode*> s;
    vector<int> temp;
    vector<vector<int> > result;
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        // cout<<value<<endl;
        // print(temp);
        if(root==NULL)
        {
            while(!s.empty()&&s.top()->right==root)
            {
                value-=temp[temp.size()-1];
                temp.pop_back(); 
                root=s.top();
                s.pop();
            }
            return result;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            if(value+root->val==sum)
            {
                // cout<<"test:"<<root->val<<endl;
                vector<int> vec(temp.begin(),temp.end());
                vec.push_back(root->val);
                result.push_back(vec);
            }
            while(!s.empty()&&s.top()->right==root)
            {
                value-=temp[temp.size()-1]; 
                temp.pop_back();
                root=s.top();
                s.pop();
            }
            return result;            
        }
        temp.push_back(root->val);
        s.push(root);
        value+=root->val;
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return result;
    }
    // for testing
    // void print(vector<int> &vec)
    // {
    //     for(vector<int>::iterator iter=vec.begin();iter!=vec.end();iter++)
    //     {
    //         cout<<*iter<<";";
    //     }
    //     cout<<endl;
    // }
};

// greater solution
// class Solution {
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         vector<vector<int> > paths;
//         vector<int> path;
//         findPaths(root, sum, path, paths);
//         return paths;  
//     }
// private:
//     void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
//         if (!node) return;
//         path.push_back(node -> val);
//         if (!(node -> left) && !(node -> right) && sum == node -> val)
//             paths.push_back(path);
//         findPaths(node -> left, sum - node -> val, path, paths);
//         findPaths(node -> right, sum - node -> val, path, paths);
//         path.pop_back();
//     }
// };