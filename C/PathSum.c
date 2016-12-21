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
bool pathSum(struct TreeNode * root,int sum,int value)
{
    if(root->left==NULL&&root->right==NULL)
    {
        if(root->val+sum==value)
            return true;
        return false;
    }
    else if(root->left!=NULL&&root->right!=NULL)
    {
        return pathSum(root->left,sum+root->val,value)||pathSum(root->right,sum+root->val,value);
    }
    else if(root->left!=NULL)
    {
        return pathSum(root->left,sum+root->val,value);
    }
    else
    {
        return pathSum(root->right,sum+root->val,value);        
    }
}

bool hasPathSum(struct TreeNode *root,int sum)
{
    if(root==NULL)
        return false;
    return pathSum(root,0,sum);
}
