#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	int *data;
	int size;
	int front;
	int rear;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue *myCircularQueueCreate(int k)
{
	MyCircularQueue *queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	queue->data = (int *)malloc(sizeof(int) * (k + 1));
	queue->front = queue->rear = 0;
	queue->size = k + 1;
	return queue;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue *obj)
{
	return (obj->front + 1) % obj->size == obj->rear;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;
	obj->data[obj->rear] = value;
	obj->rear = (obj->rear - 1 + obj->size) % obj->size;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->front = (obj->front - 1 + obj->size) % obj->size;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue *obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->data[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue *obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	int index = (obj->rear + 1) % obj->size;
	return obj->data[index];
}

void myCircularQueueFree(MyCircularQueue *obj)
{
	if (obj)
	{
		if (obj->data)
			free(obj->data);
		free(obj);
	}
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
