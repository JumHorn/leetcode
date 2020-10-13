#include <stdlib.h>

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

void freeList(struct ListNode *head)
{
	while (head)
	{
		struct ListNode *tmp = head;
		head = head->next;
		free(tmp);
	}
}

typedef struct ExamRoom
{
	int N;
	int listSize;
	struct ListNode *head;
} ExamRoom;

ExamRoom *examRoomCreate(int N)
{
	ExamRoom *res = (ExamRoom *)malloc(sizeof(ExamRoom));
	res->N = N;
	res->listSize = 0;
	res->head = createNode(0); //dummy node
	return res;
}

int examRoomSeat(ExamRoom *obj)
{
	if (obj->listSize++ == 0) //++listSize
	{
		obj->head->next = createNode(0);
		return 0;
	}
	struct ListNode *node = obj->head, *insertNode;
	int pre = node->next->val, cur, d = -1, res = obj->N - 1;
	for (node = node->next; node->next; node = node->next)
	{
		cur = node->next->val;
		if (cur - pre > 1)
		{
			int emptyseat = (cur - pre) / 2 + pre;
			if (emptyseat - pre > d)
			{
				d = emptyseat - pre;
				res = emptyseat;
				insertNode = node;
			}
		}
		pre = cur;
	}
	if (obj->N - 1 - pre > d)
	{
		d = obj->N - 1 - pre;
		res = obj->N - 1;
		insertNode = node;
	}
	cur = obj->head->next->val;
	if (cur >= d)
	{
		d = cur;
		res = 0;
		insertNode = obj->head;
	}
	struct ListNode *newnode = createNode(res);
	newnode->next = insertNode->next;
	insertNode->next = newnode;
	return res;
}

void examRoomLeave(ExamRoom *obj, int p)
{
	struct ListNode *node = obj->head;
	while (node->next->val != p)
		node = node->next;
	node->next = node->next->next;
	--obj->listSize;
}

void examRoomFree(ExamRoom *obj)
{
	if (obj)
	{
		freeList(obj->head);
		free(obj);
	}
}

/**
 * Your ExamRoom struct will be instantiated and called as such:
 * ExamRoom* obj = examRoomCreate(N);
 * int param_1 = examRoomSeat(obj);

 * examRoomLeave(obj, p);

 * examRoomFree(obj);
*/