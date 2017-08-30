#include<iostream>
#include<cmath>
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
    int sum;
    int findTilt(TreeNode* root) {
        sum=0;
        return LeafDiff(root);
        
    }
    int LeafDiff(TreeNode* root)
    {
        if(!root)
        {
            return sum;
        }
        sum+=abs(LeafSum(root->left)-LeafSum(root->right));
        LeafDiff(root->left);
        LeafDiff(root->right);
        return sum;
    }
    int LeafSum(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }
        return LeafSum(node->left)+LeafSum(node->right)+node->val;
    }
};

int main()
{}

// public class Solution {
//     int tilt=0;
//     public int findTilt(TreeNode root) {
//         traverse(root);
//         return tilt;
//     }
//     public int traverse(TreeNode root)
//     {
//         if(root==null )
//             return 0;
//         int left=traverse(root.left);
//         int right=traverse(root.right);
//         tilt+=Math.abs(left-right);
//         return left+right+root.val;
//     }
// }