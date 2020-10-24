#include <stdbool.h>
#include <stdlib.h>

//stack
typedef struct stack
{
	int *data;
	int top;
	int capacity;
} stack;

stack *stack_init(int size)
{
	stack *s = (stack *)malloc(sizeof(stack));
	s->capacity = size;
	s->data = (int *)malloc(sizeof(int) * s->capacity);
	s->top = -1;
	return s;
}

void stack_release(stack *s)
{
	if (s)
	{
		if (s->data)
			free(s->data);
		free(s);
	}
}

int stack_size(stack *s)
{
	return s->top + 1;
}

bool stack_empty(stack *s)
{
	return s->top == -1;
}

void stack_push(stack *s, int val)
{
	s->data[++s->top] = val;
}

int stack_peek(stack *s)
{
	if (stack_empty(s))
		return 0;
	return s->data[s->top];
}

int stack_pop(stack *s)
{
	if (stack_empty(s))
		return 0;
	return s->data[s->top--];
}
/********end of stack********/

typedef struct
{
	stack *in;
	stack *out;
} MyQueue;

/** Initialize your data structure here. */

MyQueue *myQueueCreate()
{
	MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
	queue->in = stack_init(1000);
	queue->out = stack_init(1000);
	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x)
{
	stack_push(obj->in, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj)
{
	int res = myQueuePeek(obj);
	stack_pop(obj->out);
	return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj)
{
	if (stack_empty(obj->out))
	{
		while (!stack_empty(obj->in))
			stack_push(obj->out, stack_pop(obj->in));
	}
	return stack_peek(obj->out);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *obj)
{
	return stack_empty(obj->in) && stack_empty(obj->out);
}

void myQueueFree(MyQueue *obj)
{
	if (obj)
	{
		if (obj->in)
			free(obj->in);
		if (obj->out)
			free(obj->out);
		free(obj);
	}
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/