
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

int getDecimalValue(struct ListNode *head)
{
	int res = 0;
	while (head)
	{
		res = ((res << 1) | head->val);
		head = head->next;
	}
	return res;
}