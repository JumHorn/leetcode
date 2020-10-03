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
	struct ListNode *head;
	struct ListNode *tail;
	int size;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList *myLinkedListCreate()
{
	MyLinkedList *list = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	list->head = list->tail = NULL;
	list->size = 0;
	return list;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList *obj, int index)
{
	if (index >= obj->size || index < 0)
		return -1;
	struct ListNode *node = obj->head;
	while (--index >= 0)
		node = node->next;
	return node->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
	struct ListNode *node = createNode(val);
	if (obj->size == 0)
		obj->head = obj->tail = node;
	else
	{
		node->next = obj->head;
		obj->head = node;
	}
	++obj->size;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
	struct ListNode *node = createNode(val);
	if (obj->size == 0)
		obj->head = obj->tail = node;
	else
	{
		obj->tail->next = node;
		obj->tail = node;
	}
	++obj->size;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
	if (index > obj->size || index < 0)
		return;
	struct ListNode *node = createNode(val);
	if (obj->size == 0 || index == 0)
		myLinkedListAddAtHead(obj, val);
	else if (obj->size == index)
	{
		obj->tail->next = node;
		obj->tail = node;
	}
	else
	{
		struct ListNode *tmp = obj->head;
		while (--index != 0)
			tmp = tmp->next;
		node->next = tmp->next;
		tmp->next = node;
	}
	++obj->size;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
	if (index >= obj->size || index < 0)
		return;
	struct ListNode *node = obj->head;
	if (index == 0)
	{
		obj->head = obj->head->next;
		free(node);
	}
	else
	{
		for (int i = 0; i < index - 1; ++i)
			node = node->next;
		if (index == obj->size - 1)
			obj->tail = node;
		struct ListNode *tmp = node->next;
		node->next = tmp->next;
		free(tmp);
	}
	--obj->size;
}

void myLinkedListFree(MyLinkedList *obj)
{
	if (obj)
	{
		struct ListNode *tmp = obj->head;
		while (obj->head)
		{
			tmp = obj->head;
			obj->head = obj->head->next;
			free(tmp);
		}
		free(obj);
	}
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/