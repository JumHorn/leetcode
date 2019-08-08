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
    void reorderList(ListNode* head) {
		if(head==NULL)
			return;
		ListNode* walker=head,*mid=head,*runner=head;
		while(runner!=NULL&&runner->next!=NULL)
		{
			walker=walker->next;
			runner=runner->next->next;
		}
		mid=walker;
		ListNode* tmp=mid->next;
		tmp=reverse(tmp);
		mid->next=NULL;
		while(tmp!=NULL)
		{
			ListNode* tmp1=tmp;
			tmp=tmp->next;
			tmp1->next=head->next;
			head->next=tmp1;
			head=head->next->next;
		}
    }

	ListNode* reverse(ListNode* root)
	{
		if(root==NULL||root->next==NULL)
			return root;
		ListNode* res=reverse(root->next);
		root->next->next=root;
		root->next=NULL;
		return res;
	}
};
