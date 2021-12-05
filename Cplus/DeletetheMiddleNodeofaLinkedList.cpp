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
	ListNode *deleteMiddle(ListNode *head)
	{
		int size = 0;
		for (ListNode *p = head; p; p = p->next)
			++size;
		if (size <= 1)
			return nullptr;
		ListNode dummy;
		dummy.next = head;
		ListNode *pre = &dummy, *mid = head;
		size = size / 2;
		for (int i = 0; i < size; ++i)
		{
			mid = mid->next;
			pre = pre->next;
		}
		pre->next = mid->next;
		return head;
	}
};