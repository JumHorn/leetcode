
//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	bool hasCycle(ListNode *head)
	{
		if (head == nullptr)
			return false;
		ListNode *tortoise = head, *hare = head->next;
		while (hare && hare->next)
		{
			tortoise = tortoise->next;
			hare = hare->next->next;
			if (tortoise == hare)
				return true;
		}
		return false;
	}
};