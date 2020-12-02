
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
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		ListNode *tail = head, *res = head;
		int count = 0;
		while (tail != nullptr && ++count != k)
			tail = tail->next;
		if (count == k)
		{
			ListNode *remain = reverseKGroup(tail->next, k);
			tail->next = nullptr;
			res = reverseList(head);
			head->next = remain;
		}
		return res;
	}

	ListNode *reverseList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *res = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return res;
	}
};