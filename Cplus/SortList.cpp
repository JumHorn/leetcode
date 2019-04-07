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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
			return head;
		ListNode* mid=head,*quicker=head->next;
		while(quicker!=NULL&&quicker->next!=NULL)
		{
			quicker=quicker->next->next;
			mid=mid->next;
		}
		ListNode* root=mid->next;
		mid->next=NULL;
		ListNode* first=sortList(head);
		ListNode* second=sortList(root);
		return merge(first,second);
    }

	ListNode* merge(ListNode* first,ListNode* second)
	{
		ListNode* tmp=new ListNode(0);
		ListNode* res=tmp;
		while(first!=NULL&&second!=NULL)
		{
			if(first->val>second->val)
			{
				tmp->next=second;
				second=second->next;
				tmp=tmp->next;
			}
			else
			{
				tmp->next=first;
				first=first->next;
				tmp=tmp->next;
			}
		}
		if(first==NULL)
			tmp->next=second;
		if(second==NULL)
			tmp->next=first;
		return res->next;
	}
};

//[19,14,5,-3,1,8]
int main()
{
	ListNode* root=new ListNode(19);
	ListNode* tmp=root;
	tmp->next=new ListNode(14);
	tmp=tmp->next;
	tmp->next=new ListNode(5);
	tmp=tmp->next;
	tmp->next=new ListNode(-3);
	tmp=tmp->next;
	tmp->next=new ListNode(1);
	tmp=tmp->next;
	tmp->next=new ListNode(8);

	Solution sol;
	sol.sortList(root);
}