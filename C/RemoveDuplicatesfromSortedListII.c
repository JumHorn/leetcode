
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (!head)
		return head;
	struct ListNode** res = &head;
	while (*res && (*res)->next)
	{
		if ((*res)->val == (*res)->next->val)
		{
			while ((*res)->next && (*res)->val == (*res)->next->val)
				(*res)->next = (*res)->next->next;
			(*res) = (*res)->next;
		}
		else
			res = &(*res)->next;
	}
	return head;
}
