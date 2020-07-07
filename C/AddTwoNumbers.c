#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* createNode(int val)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->val = val;
	return node;
}

struct ListNode* add(struct ListNode* l1, struct ListNode* l2, int carry)
{
	if (!l1 && !l2)
	{
		if (carry == 0)
			return NULL;
		return createNode(1);
	}
	if (!l1)
	{
		struct ListNode* node = createNode((l2->val + carry) % 10);
		node->next = add(l1, l2->next, (l2->val + carry) / 10);
		return node;
	}
	if (!l2)
	{
		struct ListNode* node = createNode((l1->val + carry) % 10);
		node->next = add(l1->next, l2, (l1->val + carry) / 10);
		return node;
	}
	carry = l1->val + l2->val + carry;
	struct ListNode* node = createNode(carry % 10);
	node->next = add(l1->next, l2->next, carry / 10);
	return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	return add(l1, l2, 0);
}
