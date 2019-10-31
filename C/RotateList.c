#include<stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* rotateRight(struct ListNode* head, int k){
	if(!head||k==0)
		return head;
	int len=1;
	struct ListNode* rear=head,*runner=head;
	while(rear->next!=NULL)
	{
		len++;
		rear=rear->next;
	}
	rear->next=head;
	len=len-k%len-1;
	for(int i=0;i<len;i++)
		runner=runner->next;
	head=runner->next;
	runner->next=NULL;
	return head;
}


