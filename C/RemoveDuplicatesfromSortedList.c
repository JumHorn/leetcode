#include<stdio.h>
// definition for singl-linked list
struct ListNode
{
	int val;
	struct ListNode *next;
};

int main()
{}

struct ListNode* deleteDuplicates(struct ListNode *head)
{
	struct ListNode *p;
	p=head;
	if(p==NULL||p->next==NULL)
	{
		return head;
	}
	else
	{
		if(p->val==p->next->val)
			p->next=p->next->next;
		else
			p=p->next;
		 deleteDuplicates(p);
	}
	return head;
}
