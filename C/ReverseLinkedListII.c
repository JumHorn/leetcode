
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
	if (n == m)
		return head;
	struct ListNode *res = head, *tail = 0, *data = head;
	for (int i = 2; i < m; ++i)
		head = head->next;
	if (m != 1)
		data = head->next;
	tail = data->next;
	for (int i = 0; i < n - m; ++i)
	{
		struct ListNode *tmp = tail->next;
		tail->next = data;
		data = tail;
		tail = tmp;
	}
	if (m == 1)
	{
		head->next = tail;
		res = data;
	}
	else
	{
		head->next->next = tail;
		head->next = data;
	}
	return res;
}