
// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *pA = headA, *pB = headB;
		if (!pA || !pB)
			return nullptr;
		while (pA || pB)
		{
			if (pA == pB)
				return pA;
			if (pA == nullptr)
				pA = headB;
			if (pB == nullptr)
				pB = headA;
			if (pA == pB)
				return pA;
			pA = pA->next;
			pB = pB->next;
		}
		return nullptr;
	}
};