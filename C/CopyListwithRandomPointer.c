#include <stdlib.h>

//Definition for a Node.
struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

struct Node* createNode(int val)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->val = val;
	node->next = node->random = NULL;
	return node;
}

struct Node* copyRandomList(struct Node* head)
{
	if (!head)
		return NULL;
	for (struct Node* p = head; p; p = p->next)
	{
		struct Node* node = createNode(p->val);
		node->next = p->next;
		p->next = node;
		p = p->next;
	}
	for (struct Node* p = head; p; p = p->next)
	{
		if (p->random)
			p->next->random = p->random->next;
		p = p->next;
	}
	struct Node* res = head->next;
	for (struct Node* p = head->next; p; p = p->next)
	{
		if (p->next)
			p->next = p->next->next;
	}
	return res;
}
