
//definition for singly-linked list
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
	if (!head || !head->next)
		return head;
	struct ListNode *res = head->next;
	head->next = swapPairs(res->next);
	res->next = head;
	return res;
}