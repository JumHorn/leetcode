#include<stdio.h>
//definition for singly-linked list
struct ListNode
{
	int val;
	struct ListNode *next;
};

int main()
{
	struct ListNode * swapPairs(struct ListNode *head);
}

struct ListNode * swapPairs(struct ListNode *head)
{
	if(head==NULL||head->next==NULL)
	{
		struct ListNode *temp,*result;
		temp = head->next->next;
		result = head->next;
		result->next=head;
		head->next = swapPairs(temp);
		return result;
	}
	return head;
}
