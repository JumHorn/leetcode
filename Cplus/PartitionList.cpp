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
    ListNode* partition(ListNode* head, int x) {
        ListNode* tmp=head;
		while(tmp!=NULL&&tmp->val!=x)
			tmp=tmp->next;
		while(tmp!=NULL&&tmp->next!=NULL)
		{
			if(tmp->next->val<x)
			{
				ListNode* tmp1=tmp->next;
				ListNode* tmp2=tmp->next->next;
				tmp1->next=head;
				head=tmp1;
				tmp->next=tmp2;
				tmp=tmp->next;
			}
		}
		return head;
    }
};
