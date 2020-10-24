#include <stdbool.h>
#include <stdlib.h>

//circle queue
typedef struct queue
{
	int *data;
	int size;
	int front;
	int rear;
} queue;

queue *queue_init(int size)
{
	queue *q = (queue *)malloc(sizeof(queue));
	q->size = size + 1;
	q->data = (int *)malloc(sizeof(int) * q->size);
	q->front = q->rear = 0;
	return q;
}

void queue_release(queue *q)
{
	if (q)
	{
		if (q->data)
			free(q->data);
		free(q);
	}
}

int queue_size(queue *q)
{
	return (q->front - q->rear + q->size) % q->size; //size
}

bool queue_empty(queue *q)
{
	return q->front == q->rear; //is empty
}

bool queue_full(queue *q)
{
	return (q->front + 1) % q->size == q->rear; //is full
}

void queue_push_back(queue *q, int val)
{
	if (queue_full(q))
		return;
	q->data[q->rear] = val;
	q->rear = (q->rear - 1 + q->size) % q->size; //push back
}

int queue_peek_back(queue *q)
{
	if (queue_empty(q))
		return 0;
	return q->data[(q->rear + 1) % q->size];
}

int queue_pop_back(queue *q)
{
	if (queue_empty(q))
		return 0;
	q->rear = (q->rear + 1) % q->size; //pop back
	return q->data[q->rear];
}

void queue_push_front(queue *q, int val)
{
	if (queue_full(q))
		return;
	q->front = (q->front + 1) % q->size; //push front
	q->data[q->front] = val;
}

int queue_peek_front(queue *q)
{
	if (queue_empty(q))
		return 0;
	return q->data[q->front];
}

int queue_pop_front(queue *q)
{
	if (queue_empty(q))
		return 0;
	int res = q->data[q->front];
	q->front = (q->front - 1 + q->size) % q->size; //pop front
	return res;
}
/********end of circle queue********/

typedef struct
{
	queue *q;
} MyStack;

/** Initialize your data structure here. */

MyStack *myStackCreate()
{
	MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
	stack->q = queue_init(1000);
	return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack *obj, int x)
{
	queue_push_back(obj->q, x);
	int size = queue_size(obj->q);
	while (--size > 0)
		queue_push_back(obj->q, queue_pop_front(obj->q));
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack *obj)
{
	return queue_pop_front(obj->q);
}

/** Get the top element. */
int myStackTop(MyStack *obj)
{
	return queue_peek_front(obj->q);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack *obj)
{
	return queue_empty(obj->q);
}

void myStackFree(MyStack *obj)
{
	if (obj)
	{
		if (obj->q)
			queue_release(obj->q);
		free(obj);
	}
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/