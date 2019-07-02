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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** indirect=&head;
		while((*indirect)!=NULL&&(*indirect)->next!=NULL)
		{
			if((*indirect)->val==(*indirect)->next->val)
			{
				while((*indirect)!=NULL&&(*indirect)->next!=NULL&&(*indirect)->val==(*indirect)->next->val)
					*indirect=(*indirect)->next;
				if((*indirect)!=NULL)
					*indirect=(*indirect)->next;
			}
			else
				indirect=&((*indirect)->next);
		}
		return head;
    }
};
