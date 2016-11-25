#include<stdio.h>
//definition for a singly-linked list
struct ListNode
{
	int val;
	struct ListNode *next;
};

int main()
{
	struct ListNode * mergeTwoList(struct ListNode* l1,struct ListNode *l2);
}

struct ListNode * mergeTwoList(struct ListNode* l1,struct ListNode *l2)
{
	if(l1==NULL)
	{
		return l2;
	}
	if(l2==NULL)
	{
		return l1;
	}
	ListNode *ret = NULL;
	if (l1->val < l2->val)
	{
		ret = l1;
		ret->next = mergeTwoLists(l1->next, l2);
	}
	else
	{
		ret = l2;
		ret->next = mergeTwoLists(l1, l2->next);
	}    
	return ret;
}
