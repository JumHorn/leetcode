#include<iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
		if(head==NULL||head->next==NULL)
		{
			return head;
		}
		ListNode* even=head;
		ListNode* odd=head->next;
		ListNode* tail=odd->next;
		while(tail!=NULL)
		{
			odd->next=tail->next;
			odd=odd->next;
			tail->next=even->next;
			even->next=tail;
			even=even->next;
			tail=odd;
			if(tail!=NULL)
			tail=tail->next;
		}
		return head;
    }
};
