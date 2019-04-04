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
        ListNode* tmp=head,*insert=NULL;
		while(tmp!=NULL&&tmp->val<x)
        {
            insert=tmp;
			tmp=tmp->next;
        }
		while(tmp!=NULL&&tmp->next!=NULL)
		{
			if(tmp->next->val<x)
			{
				ListNode* tmp1=tmp->next;
				ListNode* tmp2=tmp->next->next;
                if(insert!=NULL)
                {
                    tmp1->next=insert->next;
                    insert->next=tmp1;
                    tmp->next=tmp2;
                    insert=insert->next;
                }
                else
                {
                    tmp1->next=head;
                    insert=tmp1;
                    head=insert;
                    tmp->next=tmp2;
                }
			}
            else
                tmp=tmp->next;
		}
		return head;
    }
};
