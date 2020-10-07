#include <stdbool.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

// LinkedList definition
typedef struct LinkedList
{
	int start;
	int end;
	struct LinkedList *next;
} LinkedList;

LinkedList *createNode(int start, int end)
{
	LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
	node->start = start;
	node->end = end;
	node->next = NULL;
	return node;
}

void freeList(LinkedList *head)
{
	while (head)
	{
		LinkedList *tmp = head;
		head = head->next;
		free(tmp);
	}
}
// end of LinkedList definition

typedef struct
{
	LinkedList *calendar;
	LinkedList *overlap;
} MyCalendarTwo;

MyCalendarTwo *myCalendarTwoCreate()
{
	MyCalendarTwo *res = (MyCalendarTwo *)malloc(sizeof(MyCalendarTwo));
	res->calendar = createNode(0, 0);
	res->overlap = createNode(0, 0);
	return res;
}

void myCalendarAdd(LinkedList *obj, int start, int end)
{
	LinkedList *node = createNode(start, end);
	node->start = start;
	node->end = end;
	node->next = obj->next;
	obj->next = node;
}

bool myCalendarTwoBook(MyCalendarTwo *obj, int start, int end)
{
	LinkedList *overlap = obj->overlap;
	while (overlap->next)
	{
		if (overlap->next->start < end && overlap->next->end > start)
			return false;
		overlap = overlap->next;
	}
	LinkedList *calendar = obj->calendar;
	while (calendar->next)
	{
		if (calendar->next->start < end && calendar->next->end > start)
			myCalendarAdd(obj->overlap, max(calendar->next->start, start), min(calendar->next->end, end));
		calendar = calendar->next;
	}
	myCalendarAdd(calendar, start, end);
	return true;
}

void myCalendarTwoFree(MyCalendarTwo *obj)
{
	if (obj)
	{
		freeList(obj->calendar);
		freeList(obj->overlap);
		free(obj);
	}
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);

 * myCalendarTwoFree(obj);
*/