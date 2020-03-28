

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

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	struct ListNode *tail = head, *res = head;
	int count = 0;
	while (tail && ++count != k)
		tail = tail->next;
	if (count == k)
	{
		struct ListNode *tmp = reverseKGroup(tail->next, k);
		tail->next = 0;
		res = reverseList(head);
		head->next = tmp;
	}
	return res;
}