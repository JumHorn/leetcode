
// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode *pA = headA, *pB = headB;
	if (!pA || !pB)
		return 0;
	while (pA != pB)
	{
		pA = (pA ? pA->next : headB);
		pB = (pB ? pB->next : headA);
	}
	return pA;
}
