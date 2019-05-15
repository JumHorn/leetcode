#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* tail=head,*res=head,*next_head=head;
		int i=1;
        while(tail!=NULL)
		{
			if(i==k)
			{
				res=tail;
				next_head=tail->next;
				break;
			}
			i++;
			tail=tail->next;
		}
		if(tail==NULL)
            return res;
		reverse(head,tail);

		tail=next_head;
		while(tail!=NULL)
		{
			tail=next_head;
			i=1;
			while(tail!=NULL)
			{
				if(i==k)
				{
					head->next=tail;
					head=next_head;
					next_head=tail->next;
					reverse(head,tail);
					break;
				}
				i++;
				tail=tail->next;
			}
		}
        head->next=next_head;

		return res;
    }

	void reverse(ListNode* head,ListNode* tail)
	{
		if(head==tail->next||head->next==tail->next)
			return;
		reverse(head->next,tail);
		head->next->next=head;
		head->next=NULL;
	}
};
