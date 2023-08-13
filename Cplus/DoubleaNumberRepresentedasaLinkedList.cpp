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
	ListNode *doubleIt(ListNode *head)
	{
		head = reverseList(head);
		ListNode **d = &head;
		for (int carry = 0; carry != 0 || (*d) != nullptr; d = &(*d)->next)
		{
			if (*d == nullptr)
			{
				*d = new ListNode(carry);
				break;
			}
			int val = carry + (*d)->val * 2;
			carry = val / 10;
			(*d)->val = val % 10;
		}
		return reverseList(head);
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