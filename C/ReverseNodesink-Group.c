

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

struct ListNode *doReverseKGroup(struct ListNode *head, struct ListNode *tail, int k, int count)
{
	if (!tail)
		return head;
	if (count != 0)
		return doReverseKGroup(head, tail->next, k, count - 1);
	struct ListNode *res = doReverseKGroup(tail->next, tail->next, k, k - 1);
	tail->next = 0;
	reverseList(head);
	head->next = res;
	return tail;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	return doReverseKGroup(head, head, k, k - 1);
}
