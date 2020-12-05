
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
	ListNode *partition(ListNode *head, int x)
	{
		ListNode dummy1, dummy2;
		ListNode *p1 = &dummy1, *p2 = &dummy2;
		while (head)
		{
			if (head->val < x)
				p1 = p1->next = head;
			else
				p2 = p2->next = head;
			head = head->next;
		}
		p2->next = nullptr;
		p1->next = dummy2.next;
		return dummy1.next;
	}
};