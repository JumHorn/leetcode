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
        divide(head,NULL);
		return head;
    }

	ListNode* divide(ListNode* start,ListNode* end)
	{
		if(start==end||start->next==end)
			return start;
		ListNode* mid=start,*quicker=start->next;
		while(quicker!=end&&quicker->next!=end)
		{
			quicker=quicker->next->next;
			mid=mid->next;
		}
		mid=divide(start,mid->next);
		mid=divide(mid->next,end);
		return conquer(start,mid,end);
	}

	ListNode* conquer(ListNode* start,ListNode* mid,ListNode* end)
	{
		ListNode* s=start,*m=mid->next;
		while(s!=mid->next&&m!=end)
		{
			if(s->val>m->val)
			{
                ListNode* tmp=m;
                m=m->next;
                mid->next=m;
                tmp->next=s->next;
                s->next=tmp;
                    
				int t=s->val;
				s->val=tmp->val;
				tmp->val=t;
				mid=mid->next;
			}
			s=s->next;
		}
        
        // ListNode* p=start;
        // while(p!=end)
        // {
        //     cout<<p->val<<" ";
        //     p=p->next;
        // }
        // cout<<endl;
		return mid;
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