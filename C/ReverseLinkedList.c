
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