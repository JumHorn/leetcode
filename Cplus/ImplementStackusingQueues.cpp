#include<queue>
using namespace std;

class MyStack {
	queue<int> q1;
	queue<int> q2;
	bool flag;

	void dotransfer(queue<int>& q1,queue<int>& q2)
	{
		while(q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
		}
	}
	void transfer()
	{
		if(flag)
			dotransfer(q1,q2);
		else
			dotransfer(q2,q1);
		flag=!flag;
	}

public:
    /** Initialize your data structure here. */
    MyStack() {
        flag=true;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(flag)
			q1.push(x);
		else
			q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		int res;
        if(flag)
		{
			transfer();
			res=q1.front();
			q1.pop();
		}
		else
		{
			transfer();
			res=q2.front();
			q2.pop();
		}
		return res;
    }
    
    /** Get the top element. */
    int top() {
		int res;
        if(flag)
		{
			transfer();
			res=q1.front();
			q2.push(res);
			q1.pop();
		}
		else
		{
			transfer();
			res=q2.front();
			q1.push(res);
			q2.pop();
		}
		return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
