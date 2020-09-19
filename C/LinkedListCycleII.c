
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
	if (!head)
		return 0;
	struct ListNode *tortoise = head, *hare = head->next;
	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
			break;
	}
	if (hare && hare->next)
	{
		tortoise = head;
		hare = hare->next;
		while (tortoise != hare)
		{
			tortoise = tortoise->next;
			hare = hare->next;
		}
		return hare;
	}
	return 0;
}