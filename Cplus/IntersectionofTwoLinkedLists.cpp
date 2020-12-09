
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
		while (pA != pB)
		{
			pA = (pA ? pA->next : headB);
			pB = (pB ? pB->next : headA);
		}
		return pA;
	}
};