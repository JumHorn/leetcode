#include <stdlib.h>
#include <string.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

int listSize(struct ListNode* head)
{
	if (!head)
		return 0;
	return listSize(head->next) + 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize)
{
	*returnSize = k;
	struct ListNode** res = (struct ListNode**)malloc(sizeof(struct ListNode*) * (*returnSize));
	memset(res, 0, sizeof(struct ListNode*) * (*returnSize));
	int size = listSize(root);
	int part = size / k;
	for (int i = 0; i < k; ++i)
	{
		res[i] = root;
		for (int j = 0; j < part - (i >= size % k ? 1 : 0); ++j)
			root = root->next;
		if (root)
		{
			struct ListNode* p = root;
			root = root->next;
			p->next = NULL;
		}
	}
	return res;
}
