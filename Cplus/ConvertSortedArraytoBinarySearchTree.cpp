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
 
//height balanced BST
//每个节点都是二叉平衡数，左右节点树高度相等
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
        {
            return NULL;
        }
        TreeNode* root;
        Array2BST(root,nums,0,nums.size()-1);
        return root;
    }
    // void Array2BST(TreeNode* root,vector<int>& nums,int L,int R）   
    // 指针作为参数是获得一份指针的拷贝，若改变指向，只是拷贝指针的指向，原来指针的指向不改变
    // 而指针的引用可以改变原来指针的指向 
    void Array2BST(TreeNode* &root,vector<int>& nums,int L,int R)
    {
        if(R-L>1)
        {
            int middle = (L+R)/2+(L+R)%2;
            root = new TreeNode(nums[middle]);
            Array2BST(root->left,nums,L,middle-1);
            Array2BST(root->right,nums,middle+1,R);
        }
        if(R-L==1)
        {
            root = new TreeNode(nums[R]);
            root->left = new TreeNode(nums[L]);
        }
        if(R-L==0)
        {
            root = new TreeNode(nums[R]);
        }
    }
};