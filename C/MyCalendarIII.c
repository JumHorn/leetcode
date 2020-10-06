#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	int *l = *(int**)lhs, *r = *(int**)rhs;
	if (l[0] != r[0])
		return l[0] - r[0];
	return l[1] - r[1];
}

typedef struct
{
	int** data;
	int size;
	int capacity;
} MyCalendarThree;

MyCalendarThree* myCalendarThreeCreate()
{
	MyCalendarThree* res = (MyCalendarThree*)malloc(sizeof(MyCalendarThree));
	res->capacity = 1000;
	res->size = 0;
	res->data = (int**)malloc(sizeof(int*) * res->capacity);
	for (int i = 0; i < res->capacity; ++i)
		res->data[i] = (int*)malloc(sizeof(int) * 2);
	return res;
}

int myCalendarThreeBook(MyCalendarThree* obj, int start, int end)
{
	obj->data[obj->size][0] = start;
	obj->data[obj->size][1] = 1;
	++obj->size;
	obj->data[obj->size][0] = end;
	obj->data[obj->size][1] = -1;
	++obj->size;
	qsort(obj->data, obj->size, sizeof(int*), cmp);
	int res = 0, prefixsum = 0;
	for (int i = 0; i < obj->size; ++i)
	{
		prefixsum += obj->data[i][1];
		res = max(res, prefixsum);
	}
	return res;
}

void myCalendarThreeFree(MyCalendarThree* obj)
{
	if (obj)
	{
		if (obj->data)
		{
			for (int i = 0; i < obj->capacity; ++i)
				free(obj->data[i]);
			free(obj->data);
		}
		free(obj);
	}
}

/**
 * Your MyCalendarThree struct will be instantiated and called as such:
 * MyCalendarThree* obj = myCalendarThreeCreate();
 * int param_1 = myCalendarThreeBook(obj, start, end);
 
 * myCalendarThreeFree(obj);
*/
