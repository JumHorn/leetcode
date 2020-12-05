
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
	if (m == n)
		return head;
	struct ListNode dummy, *p = &dummy, *q = head;
	dummy.next = head;
	for (int i = 1; i < m; ++i)
	{
		p = q;
		q = q->next;
	}
	struct ListNode *tail = q->next;
	for (int i = 0; i < n - m; ++i)
	{
		struct ListNode *tmp = tail->next;
		tail->next = q;
		q = tail;
		tail = tmp;
	}
	p->next->next = tail;
	p->next = q;
	return dummy.next;
}