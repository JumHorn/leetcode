
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
	ListNode *rotateRight(ListNode *head, int k)
	{
		int size = 0;
		ListNode **tail = &head;
		while (*tail != nullptr)
		{
			++size;
			tail = &(*tail)->next;
		}
		if (size < 2)
			return head;
		k = size - k % size;
		ListNode **cur = &head;
		for (int i = 0; i < k - 1; ++i)
			cur = &(*cur)->next;
		*tail = head;
		ListNode *res = (*cur)->next;
		(*cur)->next = nullptr;
		return res;
	}
};