#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *createNode(int val)
{
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->val = val;
	return node;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDiagonalOrder(int **nums, int numsSize, int *numsColSize, int *returnSize)
{
	struct ListNode *arr[100000 * 2];
	memset(arr, 0, sizeof(arr));
	*returnSize = 0;
	int maxkey = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		for (int j = 0; j < numsColSize[i]; ++j)
		{
			struct ListNode *node = createNode(nums[i][j]);
			node->next = arr[i + j];
			arr[i + j] = node;
			++*returnSize;
			maxkey = max(maxkey, i + j);
		}
	}
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0, resIndex = 0; i <= maxkey; ++i)
	{
		for (struct ListNode *head = arr[i]; head; head = head->next)
			res[resIndex++] = head->val;
	}
	return res;
}