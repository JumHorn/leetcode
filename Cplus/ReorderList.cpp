
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
	void reorderList(ListNode *head)
	{
		if (head == nullptr)
			return;
		ListNode *mid = head, *tail = head;
		while (tail != nullptr && tail->next != nullptr) //get the middle
		{
			mid = mid->next;
			tail = tail->next->next;
		}
		tail = reverseList(mid->next);
		mid->next = nullptr;
		for (ListNode *p = head; tail; p = p->next->next)
		{
			ListNode *node = tail;
			tail = tail->next;
			node->next = p->next;
			p->next = node;
		}
	}

	ListNode *reverseList(ListNode *root)
	{
		if (root == nullptr || root->next == nullptr)
			return root;
		ListNode *res = reverseList(root->next);
		root->next->next = root;
		root->next = nullptr;
		return res;
	}
};