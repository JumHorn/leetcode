
class MyCircularDeque
{
public:
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k)
	{
		data = new int[k + 1];
		front = rear = 0;
		len = k + 1;
	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value)
	{
		if (isFull())
			return false;
		front = (front + 1) % len;
		data[front] = value;
		return true;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value)
	{
		if (isFull())
			return false;
		data[rear] = value;
		rear = (len + rear - 1) % len;
		return true;
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront()
	{
		if (isEmpty())
			return false;
		front = (front - 1 + len) % len;
		return true;
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast()
	{
		if (isEmpty())
			return false;
		rear = (rear + 1) % len;
		return true;
	}

	/** Get the front item from the deque. */
	int getFront()
	{
		return isEmpty() ? -1 : data[front];
	}

	/** Get the last item from the deque. */
	int getRear()
	{
		return isEmpty() ? -1 : data[(rear + 1) % len];
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty()
	{
		return front == rear;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull()
	{
		return (front + 1) % len == rear;
	}

private:
	int *data;
	int front;
	int rear;
	int len;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */