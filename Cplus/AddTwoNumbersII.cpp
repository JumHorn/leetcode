
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		int N1 = getListSize(l1), N2 = getListSize(l2);
		if (N1 >= N2)
			l1 = recursive(l1, N1, l2, N2);
		else
			l1 = recursive(l2, N2, l1, N1);
		if (l1->val < 10)
			return l1;
		ListNode *res = new ListNode(1);
		l1->val %= 10;
		res->next = l1;
		return res;
	}

	ListNode *recursive(ListNode *l1, int N1, ListNode *l2, int N2) //N1 must be bigger than N2
	{
		if (N1 == 0)
			return nullptr;
		if (N1 > N2)
			l1->next = recursive(l1->next, N1 - 1, l2, N2);
		else
		{
			l1->next = recursive(l1->next, N1 - 1, l2->next, N2 - 1);
			l1->val += l2->val;
		}
		if (l1->next)
		{
			l1->val += l1->next->val / 10;
			l1->next->val %= 10;
		}
		return l1;
	}

	int getListSize(ListNode *head)
	{
		int res = 0;
		for (; head; head = head->next)
			++res;
		return res;
	}
};