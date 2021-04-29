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
	ListNode *reverseList(ListNode *head)
	{
		if (head == nullptr)
			return head;
		ListNode *p = head, *q = head->next;
		head->next = nullptr;
		while (q != nullptr)
		{
			ListNode *tmp = q->next;
			q->next = p;
			p = q;
			q = tmp;
		}
		return p;
	}
};
