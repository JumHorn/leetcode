#include <algorithm>  //for NULL define

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		if (m == n)
			return head;
		ListNode *dummy = new ListNode(0), *p = dummy, *q = head;
		dummy->next = head;
		n -= m;
		while (--m > 0)
		{
			p = q;
			q = q->next;
		}
		ListNode* tail = q->next;
		while (--n >= 0)
		{
			ListNode* tmp = tail->next;
			tail->next = q;
			q = tail;
			tail = tmp;
		}
		p->next->next = tail;
		p->next = q;
		return dummy->next;
	}
};
