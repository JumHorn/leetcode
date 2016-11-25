#include<stdio.h>
//definition for a binary tree node
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int main()
{
struct TreeNode * lowestCommonAncestor(struct TreeNode *root,struct TreeNode *p ,struct TreeNode *q);

}

struct TreeNode * lowestCommonAncestor(struct TreeNode *root,struct TreeNode *p ,struct TreeNode *q)
{
	if(root->val>=p->val&&root->val<=q->val||root->val<=p->val&&root->val>=q->val)
	{
		return root;
	}
	if(root->val>p->val&&root->val>q->val)
	{
		return lowestCommonAncestor(root->left,p,q);
	}
	if(root->val<p->val&&root->val<q->val)
	{
		return lowestCommonAncestor(root->right,p,q);
	}
}
