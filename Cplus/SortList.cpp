
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
	ListNode *sortList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *mid = head, *quicker = head->next;
		while (quicker != nullptr && quicker->next != nullptr)
		{
			quicker = quicker->next->next;
			mid = mid->next;
		}
		quicker = mid->next;
		mid->next = nullptr;
		head = sortList(head);
		mid = sortList(quicker);
		return merge(head, mid);
	}

	ListNode *merge(ListNode *first, ListNode *second)
	{
		if (!first)
			return second;
		if (!second)
			return first;
		if (first->val <= second->val)
		{
			first->next = merge(first->next, second);
			return first;
		}
		second->next = merge(first, second->next);
		return second;
	}
};