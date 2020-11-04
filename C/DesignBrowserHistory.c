#include <stdlib.h>

typedef struct
{
	char* history[5000];
	int top;
	int size;
} BrowserHistory;

BrowserHistory* browserHistoryCreate(char* homepage)
{
	BrowserHistory* res = (BrowserHistory*)malloc(sizeof(BrowserHistory));
	res->history[0] = homepage;
	res->top = 0;
	res->size = 1;
	return res;
}

void browserHistoryVisit(BrowserHistory* obj, char* url)
{
	obj->size = ++obj->top + 1;
	obj->history[obj->top] = url;
}

char* browserHistoryBack(BrowserHistory* obj, int steps)
{
	obj->top -= steps;
	if (obj->top < 0)
		obj->top = 0;
	return obj->history[obj->top];
}

char* browserHistoryForward(BrowserHistory* obj, int steps)
{
	obj->top += steps;
	if (obj->top >= obj->size)
		obj->top = obj->size - 1;
	return obj->history[obj->top];
}

void browserHistoryFree(BrowserHistory* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char * param_2 = browserHistoryBack(obj, steps);
 
 * char * param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/
