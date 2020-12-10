
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode dummy(0), *p = &dummy;
		for (int carry = 0; l1 || l2 || carry; carry /= 10)
		{
			if (l1)
			{
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				carry += l2->val;
				l2 = l2->next;
			}
			p->next = new ListNode(carry % 10);
			p = p->next;
		}
		return dummy.next;
	}
};