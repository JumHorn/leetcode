
int magicalString(int n)
{
	if (n == 0)
		return 0;
	if (n <= 3)
		return 1;
	n -= 3;
	//front stores data and rear not
	int size = n / 2 + 10, queue[size], front = 0, rear = 0;
	queue[rear] = 2;
	rear = (rear - 1 + size) % size; //push back

	int elements = 2, res = 1;
	while (--n >= 0)
	{
		int count = queue[front];
		front = (front - 1 + size) % size; //pop front
		elements = 3 - elements;
		if (count == 2)
		{
			queue[rear] = elements;
			rear = (rear - 1 + size) % size; //push back
			if (elements == 1)
				++res;
			--n;
		}
		queue[rear] = elements;
		rear = (rear - 1 + size) % size; //push back
		if (elements == 1 && n >= 0)
			++res;
	}
	return res;
}