

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head)
{
	if (!head)
		return head;
	struct ListNode **p = &head->next, **q;
	while (*p)
	{
		q = &head; //reset to head
		while ((*p)->val > (*q)->val)
			q = &(*q)->next;
		if (p != q)
		{
			struct ListNode *node = *p;
			*p = (*p)->next;
			node->next = *q;
			*q = node;
		}
		else
			p = &(*p)->next;
	}
	return head;
}