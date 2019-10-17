#include<stdlib.h>
#include<limits.h>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct LinkedList{
	int val;
	struct LinkedList* next;
};

void addLevel(struct TreeNode* root,struct LinkedList** list)
{
	if(!root)
		return;
	if(!*list)
	{
		*list=(struct LinkedList*)malloc(sizeof(struct LinkedList));
		(*list)->val=0;
		(*list)->next=NULL;
	}
	(*list)->val+=root->val;
	addLevel(root->left,&(*list)->next);
	addLevel(root->right,&(*list)->next);
}

int maxLevelSum(struct TreeNode* root){
	struct LinkedList *list=NULL;
	addLevel(root,&list);
	int res=1,val=list->val,level=1;
	while(list)
	{
		if(list->val>val)
		{
			val=list->val;
			res=level;
		}
		list=list->next;
		level+=1;
	}
	return res;
}
