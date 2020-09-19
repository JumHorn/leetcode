
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *merge(struct ListNode *list0, struct ListNode *list1)
{
	if (!list0)
		return list1;
	if (!list1)
		return list0;
	if (list0->val <= list1->val)
	{
		list0->next = merge(list0->next, list1);
		return list0;
	}
	list1->next = merge(list0, list1->next);
	return list1;
}

struct ListNode *sortList(struct ListNode *head)
{
	if (!head || !head->next)
		return head;
	struct ListNode *mid = head, *tail = head->next;
	while (tail && tail->next)
	{
		mid = mid->next;
		tail = tail->next->next;
	}
	tail = mid->next;
	mid->next = 0;
	head = sortList(head);
	mid = sortList(tail);
	return merge(head, mid);
}