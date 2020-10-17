#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextLargerNodes(struct ListNode* head, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * 10000);
	int stack[10000], top = -1;
	for (*returnSize = 0; head; ++*returnSize)
	{
		while (top != -1 && res[stack[top]] < head->val)
		{
			res[stack[top]] = head->val;
			--top;
		}
		res[*returnSize] = head->val;
		stack[++top] = *returnSize;
		head = head->next;
	}
	while (top != -1)
		res[stack[top--]] = 0;
	return res;
}
