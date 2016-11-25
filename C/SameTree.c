//definition for a binary tree node
#include<stdio.h>
#include<stdbool.h>
struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
};
int main()
{
	bool isSameTree(struct TreeNode *p,struct TreeNode *q);
}
bool isSameTree(struct TreeNode *p,struct TreeNode *q)
{
	if(p==NULL&&q==NULL)
	{
		return true;
	}
	else if(p!=NULL&&q!=NULL)
	{
		if(p->val!=q->val)
		{
			return false;
		}
		else
		{
			return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
		}
	}
	else
	{
		return false;
	}
}
