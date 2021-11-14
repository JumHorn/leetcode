
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
	ListNode *reverseEvenLengthGroups(ListNode *head)
	{
		ListNode *tail, dummy, *d = &dummy;
		d->next = head;
		tail = d;
		head = d;
		for (int i = 1; head->next; ++i)
		{
			int count = 0;
			for (int j = 0; j < i && tail->next; ++j)
			{
				++count;
				tail = tail->next;
			}
			if (count % 2 == 0)
			{
				ListNode *p = tail->next, *q = head->next;
				tail->next = nullptr;
				head->next = reverseList(head->next);
				head = q;
				tail = q;
				q->next = p;
			}
			else
			{
				head = tail;
			}
		}
		return dummy.next;
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