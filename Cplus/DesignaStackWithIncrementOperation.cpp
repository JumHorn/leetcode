
class CustomStack
{
public:
	CustomStack(int maxSize)
	{
		capacity = maxSize;
		stack = new int[capacity];
		top = -1;
	}

	void push(int x)
	{
		if (top + 1 < capacity)
			stack[++top] = x;
	}

	int pop()
	{
		if (top == -1)
			return -1;
		return stack[top--];
	}

	void increment(int k, int val)
	{
		for (int i = 0; i < k && i <= top; ++i)
			stack[i] += val;
	}

private:
	int *stack;
	int top;
	int capacity;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */