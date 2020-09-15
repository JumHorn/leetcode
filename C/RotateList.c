#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
	if (!head || k == 0)
		return head;
	int size = 1;
	struct ListNode *rear = head, *runner = head;
	while (rear->next != NULL)
	{
		++size;
		rear = rear->next;
	}
	rear->next = head;
	size = size - k % size - 1;
	for (int i = 0; i < size; i++)
		runner = runner->next;
	head = runner->next;
	runner->next = NULL;
	return head;
}