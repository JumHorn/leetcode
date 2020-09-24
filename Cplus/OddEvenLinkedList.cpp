

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
	ListNode *oddEvenList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *even = head;
		ListNode *odd = head->next;
		ListNode *tail = odd->next;
		while (tail != nullptr)
		{
			odd->next = tail->next;
			odd = odd->next;
			tail->next = even->next;
			even->next = tail;
			even = even->next;
			tail = odd;
			if (tail != nullptr)
				tail = tail->next;
		}
		return head;
	}
};