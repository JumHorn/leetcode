
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
	ListNode *deleteDuplicates(ListNode *head)
	{
		ListNode dummy;
		dummy.next = head;
		ListNode *p = &dummy;
		while (p->next && p->next->next)
		{
			if (p->next->val == p->next->next->val)
			{
				while (p->next->next && p->next->val == p->next->next->val)
					p->next = p->next->next;
				p->next = p->next->next;
			}
			else
				p = p->next;
		}
		return dummy.next;
	}
};