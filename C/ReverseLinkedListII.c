

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
	if (n == m)
		return head;
	struct ListNode *end = head, *data = head, *tail = head, *res = head;
	if (m == 1)
	{
		end = end->next;
		for (int i = 0; i < n - m; i++)
		{
			struct ListNode* tmp = end;
			end = end->next;
			tmp->next = tail;
			tail = tmp;
		}
		head->next = end;
		res = tail;
	}
	else
	{
		for (int i = 2; i < m; i++)
			head = head->next;
		data = head->next;
		tail = data;
		end = data->next;
		for (int i = 0; i < n - m; i++)
		{
			struct ListNode* tmp = end;
			end = end->next;
			tmp->next = tail;
			tail = tmp;
		}
		head->next = tail;
		data->next = end;
	}
	return res;
}

