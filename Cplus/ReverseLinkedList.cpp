#include <algorithm> //for NULL define

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *reverseList(ListNode *head)
	{
		if (head == NULL)
			return head;
		ListNode *p = head, *q = head->next;
		head->next = NULL;
		while (q != NULL)
		{
			ListNode *tmp = q->next;
			q->next = p;
			p = q;
			q = tmp;
		}
		return p;
	}
};
