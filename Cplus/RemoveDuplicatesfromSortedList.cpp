
// Definition for singly-linked list.
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
		if (head == nullptr)
			return head;
		ListNode *q = head;
		for (ListNode *p = head->next; p != nullptr; p = p->next)
		{
			if (p->val != q->val)
			{
				q->next = p;
				q = p;
			}
		}
		q->next = nullptr;
		return head;
	}
};