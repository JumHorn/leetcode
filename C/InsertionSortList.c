

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* insertionSortList(struct ListNode* head)
{
	if (!head)
		return head;
	struct ListNode *p = head->next, *q = head;
	while (p)
	{
		if (p->val < head->val)
		{
			q->next = p->next;
			p->next = head;
			head = p;
			p = q;
		}
		else
		{
			struct ListNode* tmp = head;
			while (tmp != p)
			{
				if (p->val < tmp->next->val)
				{
					q->next = p->next;
					p->next = tmp->next;
					tmp->next = p;
					p = q;
					break;
				}
				tmp = tmp->next;
			}
			if (tmp == p)
				q = q->next;
		}
		p = p->next;
	}
	return head;
}

