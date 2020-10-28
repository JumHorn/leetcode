#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	int *data;
	int size;
	int front;
	int rear;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque *myCircularDequeCreate(int k)
{
	MyCircularDeque *deque = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
	deque->size = k + 1;
	deque->data = (int *)malloc(sizeof(int) * deque->size);
	deque->front = deque->rear = 0;
	return deque;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque *obj)
{
	return obj->front == obj->rear;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque *obj)
{
	return (obj->front + 1) % obj->size == obj->rear;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque *obj, int value)
{
	if (myCircularDequeIsFull(obj))
		return false;
	obj->front = (obj->front + 1) % obj->size;
	obj->data[obj->front] = value;
	return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque *obj, int value)
{
	if (myCircularDequeIsFull(obj))
		return false;
	obj->data[obj->rear] = value;
	obj->rear = (obj->rear - 1 + obj->size) % obj->size;
	return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque *obj)
{
	if (myCircularDequeIsEmpty(obj))
		return false;
	obj->front = (obj->front - 1 + obj->size) % obj->size;
	return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque *obj)
{
	if (myCircularDequeIsEmpty(obj))
		return false;
	obj->rear = (obj->rear + 1) % obj->size;
	return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque *obj)
{
	if (myCircularDequeIsEmpty(obj))
		return -1;
	return obj->data[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque *obj)
{
	if (myCircularDequeIsEmpty(obj))
		return -1;
	int index = (obj->rear + 1) % obj->size;
	return obj->data[index];
}

void myCircularDequeFree(MyCircularDeque *obj)
{
	if (obj)
	{
		if (obj->data)
			free(obj->data);
		free(obj);
	}
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);

 * bool param_2 = myCircularDequeInsertLast(obj, value);

 * bool param_3 = myCircularDequeDeleteFront(obj);

 * bool param_4 = myCircularDequeDeleteLast(obj);

 * int param_5 = myCircularDequeGetFront(obj);

 * int param_6 = myCircularDequeGetRear(obj);

 * bool param_7 = myCircularDequeIsEmpty(obj);

 * bool param_8 = myCircularDequeIsFull(obj);

 * myCircularDequeFree(obj);
*/