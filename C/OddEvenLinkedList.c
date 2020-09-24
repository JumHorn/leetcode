
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* oddEvenList(struct ListNode* head)
{
	if (!head)
		return head;
	struct ListNode dummy;
	dummy.next = 0;
	struct ListNode **p = &head, *even = &dummy;
	while (*p && (*p)->next)
	{
		struct ListNode* q = (*p)->next;
		p = &(*p)->next;
		*p = (*p)->next;

		q->next = 0;
		even->next = q;
		even = even->next;
	}
	if (*p)
		p = &(*p)->next;
	*p = dummy.next;
	return head;
}
