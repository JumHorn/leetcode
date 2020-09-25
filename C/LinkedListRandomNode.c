#include <math.h>
#include <stdlib.h>

/*
Algorithm:
Reservoir Sampling
*/

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

typedef struct
{
	struct ListNode* head;
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */

Solution* solutionCreate(struct ListNode* head)
{
	Solution* res = (Solution*)malloc(sizeof(struct ListNode));
	res->head = head;
	return res;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj)
{
	int res = obj->head->val, n = 2;
	for (struct ListNode* p = obj->head->next; p; p = p->next)
	{
		if (rand() % n++ == 0)
			res = p->val;
	}
	return res;
}

void solutionFree(Solution* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
