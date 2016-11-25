#include<stdio.h>
#include<stdlib.h>
//definition for a binary tree node
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int a[50][101]={0};
int main()
{
	int ** levelOrderBottom(struct TreeNode * root,int ** columnSizes,int *returnSize);
}

//return an array of arrays of size *return 
//the sizes of the arrays are returned as *columnSizes array
//note: both returned array and *columnSize array must be malloced,assume caller calls free();

int traversal(struct TreeNode * root,int level)
{
	static int max = 0;
	if(root==NULL)
	{
		if(level>max)max=level;
		return max;
	}
	else
	{
		a[level][a[level][100]++]=root->val;

		traversal(root->left,level+1);
		traversal(root->right,level+1);
	}
	return max;
}

int ** levelOrderBottom(struct TreeNode * root,int ** columnSizes,int *returnSize)
{
	int i=0;
	*returnSize=traversal(root,0);
	int ** p = (int **)malloc(sizeof(int*)*(*returnSize));
        *columnSizes = (int *)malloc(sizeof(int)*(*returnSize));
	for(i=*returnSize;i>0;i--)
	{
		p[*returnSize-i]=a[i];
		(*columnSizes)[*returnSize-i]=a[i][100];
	}
	return p;
}

