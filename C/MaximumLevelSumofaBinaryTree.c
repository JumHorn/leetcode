#include<stdlib.h>
#include<limits.h>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void addLevel(struct TreeNode* root,int* arr,int layer,int* h)
{
	if(!root)
		return 0;
	arr[layer]+=root->val;
	if(layer>*h)
		*h=layer;
	addLevel(root->left,arr,layer+1,h);
	addLevel(root->right,arr,layer+1,h);
}

int maxLevelSum(struct TreeNode* root){
	struct LinkedList *list=NULL;
	int arr[100]={0},height;
	addLevel(root,arr,0,&height);
	int res=1,tmp=arr[0];
	for(int i=1;i<height;i++)
		if(arr[i]>tmp)
		{
			tmp=arr[i];
			res=i+1;
		}
	return res;
}