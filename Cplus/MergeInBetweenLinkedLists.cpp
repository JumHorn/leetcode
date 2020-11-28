
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
	ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
	{
		ListNode *last = list2;
		while (last->next != nullptr)
			last = last->next;
		int i = 0;
		ListNode *p = list1;
		for (; i < a - 1; ++i)
			p = p->next;
		ListNode *tmp = p->next;
		p->next = list2;
		p = tmp;
		for (; i < b; ++i)
			p = p->next;
		last->next = p;
		return list1;
	}
};