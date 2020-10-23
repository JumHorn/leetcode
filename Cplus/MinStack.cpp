#include <climits>
#include <stack>
using namespace std;

class MinStack
{
public:
	/** initialize your data structure here. */
	MinStack()
	{
		s.push({0, INT_MAX});
	}

	void push(int x)
	{
		s.push({x, min(x, s.top().second)});
	}

	void pop()
	{
		s.pop();
	}

	int top()
	{
		return s.top().first;
	}

	int getMin()
	{
		return s.top().second;
	}

private:
	stack<pair<int, int>> s; //{value,current min}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */