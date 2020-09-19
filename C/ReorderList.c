
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
	if (!head || !head->next)
		return head;
	struct ListNode *res = reverseList(head->next);
	head->next->next = head;
	head->next = 0;
	return res;
}

void reorderList(struct ListNode *head)
{
	if (!head)
		return;
	struct ListNode *middle = head, *tail = head->next;
	while (tail && tail->next)
	{
		middle = middle->next;
		tail = tail->next->next;
	}
	tail = reverseList(middle->next);
	middle->next = 0;
	for (struct ListNode *p = head; tail; p = p->next->next)
	{
		struct ListNode *node = tail;
		tail = tail->next;
		node->next = p->next;
		p->next = node;
	}
}