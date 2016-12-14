#include<stdio.h>
//definition for a binary tree node
struct TreeNode 
{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
};

int main()
{
    int minDepth(struct TreeNode *root);
}

int min(int a ,int b)
{
    if(a>b)
        return b;
    else
        return a;
}

int minDepth(struct TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return 1;
    } 
    if(root->left==NULL)
    {
        return 1+minDepth(root->right);
    }
    if(root->right==NULL)
    {
        return 1+minDepth(root->left);
    }
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
