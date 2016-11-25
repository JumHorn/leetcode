/*
   Definition for singly-linked list
   struct ListNode
   {
   int val;
   struct ListNode *next;
   };
 */
#include<stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};
int main()
{
	void deleteNode(struct ListNode * node);
}

void deleteNode(struct ListNode * node)
{
	if(node->next!=NULL)
	{
		if(node->next->next!=NULL)
		{
			node->val=node->next->val;
			node->next=node->next->next;
		}
		else
		{
			node->val=node->next->val;
			node->next=NULL;
		}
	}
}
