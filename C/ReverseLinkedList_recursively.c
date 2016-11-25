#include<stdio.h>
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
	struct ListNode *p;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	p=reverseList(head->next);
	head->next->next=head;
	head->next=NULL;
	return p;
}
