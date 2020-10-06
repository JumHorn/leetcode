#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct MyCalendar
{
	int start;
	int end;
	struct MyCalendar *next;
} MyCalendar;

MyCalendar *myCalendarCreate()
{
	MyCalendar *res = (MyCalendar *)malloc(sizeof(MyCalendar));
	res->next = NULL;
	return res;
}

bool myCalendarBook(MyCalendar *obj, int start, int end)
{
	while (obj->next)
	{
		if (obj->next->end > start)
		{
			if (obj->next->start >= end)
				break;
			return false;
		}
		obj = obj->next;
	}
	MyCalendar *node = myCalendarCreate();
	node->start = start;
	node->end = end;
	node->next = obj->next;
	obj->next = node;
	return true;
}

void myCalendarFree(MyCalendar *obj)
{
	while (obj)
	{
		MyCalendar *tmp = obj;
		obj = obj->next;
		free(tmp);
	}
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);

 * myCalendarFree(obj);
*/
