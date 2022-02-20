
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
	ListNode *mergeNodes(ListNode *head)
	{
		ListNode dummy, *d = &dummy;
		for (; head != nullptr;)
		{
			if (head->val == 0)
			{
				int sum = 0;
				for (head = head->next; head != nullptr && head->val != 0; head = head->next)
					sum += head->val;
				if (sum != 0)
				{
					d->next = new ListNode(sum);
					d = d->next;
				}
			}
		}
		return dummy.next;
	}
};