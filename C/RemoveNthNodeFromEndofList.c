
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	struct ListNode **walker = &head, *runner = head;
	for (int i = 0; i < n; ++i)
		runner = runner->next;
	while (runner)
	{
		walker = &(*walker)->next;
		runner = runner->next;
	}
	*walker = (*walker)->next;
	return head;
}
