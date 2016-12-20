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
int pathSum(struct TreeNode * root,int sum)
{
    if(root->left==NULL&&root->right==NULL)
    {
        return sum+root->val;
    }
}

bool hasPathSum(struct TreeNode *root,int sum)
{
    static int m=sum;
    if(root->val+sum>sum)
    {
        return false;
    }
    else if()
}
