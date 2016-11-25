#include<stdio.h>
//definition for singly-linked list
struct ListNode
{
	int val;
	struct ListNode *next;
};
int main()
{
	struct ListNode *removeElements(struct ListNode *head,int val);
}

struct ListNode *removeElements(struct ListNode *head,int val)
{
	if(head==NULL)
		return head;
	struct ListNode *p;
	p=head;
	while(p!=NULL&&p->val==val)
	{
		p=p->next;
	}
	if(p==NULL)
		return p;
	head=p;
	while(p!=NULL&&p->next!=NULL)
	{
		if(p->next->val==val)
		{
			p->next=p->next->next;
		}
		else
			p=p->next;
	}
	return head;
}



