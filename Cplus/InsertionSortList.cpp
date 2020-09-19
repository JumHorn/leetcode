
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
	ListNode *insertionSortList(ListNode *head)
	{
		if (!head)
			return head;
		ListNode **p = &head->next, **q;
		while (*p)
		{
			q = &head; //reset to head
			while ((*p)->val > (*q)->val)
				q = &(*q)->next;
			if (p != q)
			{
				ListNode *node = *p;
				*p = (*p)->next;
				node->next = *q;
				*q = node;
			}
			else
				p = &(*p)->next;
		}
		return head;
	}
};