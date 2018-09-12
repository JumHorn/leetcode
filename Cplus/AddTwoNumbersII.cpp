#include<iostream>
#include<list>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        list<int> n1,n2;
	    while(l1!=NULL)
		{
			n1.push_back(l1->val);
			l1=l1->next;
		}
	    while(l2!=NULL)
		{
			n2.push_back(l2->val);
			l2=l2->next;
		}
		ListNode* head=NULL;
		ListNode* tmp=NULL;
		int bit=0;
		int n,n3,n4;
		while(!n1.empty()||!n2.empty())
		{
			if(!n1.empty())
			{
				n3=n1.back();
				n1.pop_back();
			}
			else
			{
				n3=0;
			}
			if(!n2.empty())
			{
				n4=n2.back();
				n2.pop_back();
			}
			else
			{
				n4=0;
			}
			n=n3+n4+bit;
			tmp=new ListNode(n%10);
			tmp->next=head;
			head=tmp;	
			bit=n/10;
		}
		if(bit==1)
		{
			tmp=new ListNode(bit);
			tmp->next=head;
			head=tmp;
		}
		return head;
    }
};
