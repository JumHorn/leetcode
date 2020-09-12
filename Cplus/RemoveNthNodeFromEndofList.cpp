
//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode **walker = &head, *runner = head;
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
};