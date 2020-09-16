
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* partition(struct ListNode* head, int x)
{
	if (!head)
		return head;
	struct ListNode** insert = &head;
	while (*insert && (*insert)->val < x)
		insert = &(*insert)->next;
	for (struct ListNode** p = insert; *p;)
	{
		if ((*p)->val < x)
		{
			struct ListNode* rm = *p;
			*p = (*p)->next;
			rm->next = *insert;
			*insert = rm;
			insert = &(*insert)->next;
		}
		else
			p = &(*p)->next;
	}
	return head;
}
