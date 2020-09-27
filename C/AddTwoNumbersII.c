#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

int listlen(struct ListNode *head)
{
	int res = 0;
	while (head)
	{
		++res;
		head = head->next;
	}
	return res;
}

struct ListNode *createNode(int val)
{
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->val = val;
	return node;
}

struct ListNode *push_front(struct ListNode *head, int val)
{
	struct ListNode *res = createNode(val);
	res->next = head;
	return res;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	if (!(l1 || l2))
		return NULL;
	int size1 = listlen(l1), size2 = listlen(l2);
	struct ListNode *res = NULL;
	while (size1 > 0 && size2 > 0)
	{
		int sum = 0;
		if (size1 >= size2)
		{
			sum += l1->val;
			l1 = l1->next;
			--size1;
		}
		if (size2 > size1)
		{
			sum += l2->val;
			l2 = l2->next;
			--size2;
		}
		res = push_front(res, sum);
	}
	int carry = 0;
	struct ListNode *pre = NULL, *next = NULL;
	while (res || carry)
	{
		if (!res)
			res = createNode(0);
		res->val += carry;
		carry = res->val / 10;
		res->val %= 10;
		next = res->next;
		res->next = pre;
		pre = res;
		res = next;
	}
	return pre;
}