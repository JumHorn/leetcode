
// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
	struct ListNode **p = &head;
	while (*p)
	{
		if ((*p)->val == val)
			*p = (*p)->next;
		else
			p = &(*p)->next;
	}
	return head;
}