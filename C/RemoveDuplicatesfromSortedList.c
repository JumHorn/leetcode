
// definition for singl-linked list
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	if (!head)
		return head;
	struct ListNode *q = head;
	for (struct ListNode *p = head->next; p; p = p->next)
	{
		if (p->val != q->val)
		{
			q->next = p;
			q = p;
		}
	}
	q->next = 0;
	return head;
}