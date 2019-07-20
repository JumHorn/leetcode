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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res=l1;
		int bit=0,val;
		while(l1->next!=NULL&&l2->next!=NULL)
		{
			val=l1->val+l2->val+bit;
			bit=val/10;
			val%=10;
			l1->val=val;
			l1=l1->next;
			l2=l2->next;
		}
		val=l1->val+l2->val+bit;
		bit=val/10;
		val%=10;
		l1->val=val;
		if(l1->next!=NULL||l2->next!=NULL)
		{
			if(l2->next!=NULL)
				l1->next=l2->next;
			l1=l1->next;
			while(l1->next!=NULL&&bit!=0)
			{
				val=l1->val+bit;
				bit=val/10;
				val%=10;
				l1->val=val;
				l1=l1->next;
			}
			val=l1->val+bit;
			bit=val/10;
			val%=10;
			l1->val=val;
		}
		if(bit!=0)
			l1->next=new ListNode(bit);
		return res;
    }
};
