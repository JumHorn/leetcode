
//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode *reverseBetween(ListNode *head, int m, int n)
	{
		if (m == n)
			return head;
		ListNode dummy(0), *p = &dummy, *q = head;
		dummy.next = head;
		for (int i = 1; i < m; ++i)
		{
			p = q;
			q = q->next;
		}
		ListNode *tail = q->next;
		for (int i = 0; i < n - m; ++i)
		{
			ListNode *tmp = tail->next;
			tail->next = q;
			q = tail;
			tail = tmp;
		}
		p->next->next = tail;
		p->next = q;
		return dummy.next;
	}
};