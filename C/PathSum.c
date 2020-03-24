#include<stdio.h>
//definiton for a bianry tree node
struct TreeNode
{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
};
int main()
{
    bool hasPathSum(struct TreeNode * root);
}

bool hasPathSum(struct TreeNode *root,int sum)
{
    if (root == NULL) return false;
    if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
