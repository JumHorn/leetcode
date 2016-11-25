#include<stdio.h>
//definition for singly-linked list
struct ListNode
{
	int val;
	struct ListNode *next;
};

int main()
{
	struct ListNode * reverseList(struct ListNode * head);
}

struct ListNode * reverseList(struct ListNode * head)
{
	struct ListNode *p,*q,*k;
	p=q=head;
	if(p==NULL||p->next==NULL)
	{
		return p;
	}
	q=p->next;
	k=p;
	while(q!=NULL)
	{
		p=q;
		q=q->next;
		p->next=k;
		k=p;
	}
	head->next=NULL;
	return p;
}
