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

typedef struct
{
	struct ListNode **data;
	int *dataColSize;
	int dataSize;
	int c; //capacity
	int s; //size (count of all element)
	int p; //push index
	int v; //pop index
} DinnerPlates;

DinnerPlates *dinnerPlatesCreate(int capacity)
{
	int size = 100000;
	DinnerPlates *plates = (DinnerPlates *)malloc(sizeof(DinnerPlates));
	plates->dataSize = 0;
	plates->data = (struct ListNode *)malloc(sizeof(struct ListNode *) * size);
	memset(plates->data, 0, sizeof(struct ListNode *) * size);
	plates->dataColSize = (int *)malloc(sizeof(int) * size);
	memset(plates->dataColSize, 0, sizeof(int) * size);
	plates->c = capacity;
	plates->s = plates->p = plates->v = 0;
	return plates;
}

void dinnerPlatesPush(DinnerPlates *obj, int val)
{
	++obj->s;
	while (obj->p < obj->dataSize && obj->dataColSize[obj->p] == obj->c)
		++obj->p;
	if (obj->p >= obj->dataSize)
		obj->p = obj->dataSize++;

	struct ListNode *node = createNode(val);
	node->next = obj->data[obj->p];
	obj->data[obj->p] = node;
	++obj->dataColSize[obj->p];

	if (obj->p > obj->v)
		obj->v = obj->p;
}

int dinnerPlatesPop(DinnerPlates *obj)
{
	if (obj->s == 0)
		return -1;
	--obj->s;
	int res = -1;
	while (obj->v >= 0 && obj->dataColSize[obj->v] == 0)
		--obj->v;
	res = obj->data[obj->v]->val;
	obj->data[obj->v] = obj->data[obj->v]->next;
	--obj->dataColSize[obj->v];
	if (obj->p > obj->v)
		obj->p = obj->v;
	return res;
}

int dinnerPlatesPopAtStack(DinnerPlates *obj, int index)
{
	int res = -1;
	if (index < obj->dataSize)
	{
		if (obj->data[index])
		{
			--obj->s;
			--obj->dataColSize[index];
			res = obj->data[index]->val;
			obj->data[index] = obj->data[index]->next;
			if (obj->p > index)
				obj->p = index;
		}
	}
	return res;
}

void dinnerPlatesFree(DinnerPlates *obj)
{
	if (obj)
	{
		for (int i = 0; i < obj->dataSize; ++i)
		{
			for (struct ListNode *node = obj->data[i]; node;)
			{
				struct ListNode *deleted_node = node;
				node = node->next;
				free(deleted_node);
			}
		}
		free(obj);
	}
}

/**
 * Your DinnerPlates struct will be instantiated and called as such:
 * DinnerPlates* obj = dinnerPlatesCreate(capacity);
 * dinnerPlatesPush(obj, val);

 * int param_2 = dinnerPlatesPop(obj);

 * int param_3 = dinnerPlatesPopAtStack(obj, index);

 * dinnerPlatesFree(obj);
*/