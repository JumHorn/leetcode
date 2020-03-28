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
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		ListNode *tail = head, *res = head;
		int count = 0;
		while (tail != NULL && ++count != k)
			tail = tail->next;
		if (count == k)
		{
			ListNode *tmp = reverseKGroup(tail->next, k);
			tail->next = NULL;
			res = reverseList(head);
			head->next = tmp;
		}
		return res;
	}

	ListNode *reverseList(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *res = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return res;
	}
};