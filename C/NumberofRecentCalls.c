#include <stdlib.h>

typedef struct
{
	int queue[3002];
	int front;
	int rear;
	int size;
} RecentCounter;

RecentCounter *recentCounterCreate()
{
	RecentCounter *res = (RecentCounter *)malloc(sizeof(RecentCounter));
	res->front = res->rear = 0;
	res->size = 3002;
	return res;
}

int recentCounterPing(RecentCounter *obj, int t)
{
	while (obj->front != obj->rear && obj->queue[obj->front] < t - 3000)
		obj->front = (obj->front - 1 + obj->size) % obj->size; //pop front;
	obj->queue[obj->rear] = t;
	obj->rear = (obj->rear - 1 + obj->size) % obj->size; //push back
	return (obj->front - obj->rear + obj->size) % obj->size;
}

void recentCounterFree(RecentCounter *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/