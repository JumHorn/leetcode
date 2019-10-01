#include<stack>
using namespace std;

class MyQueue {
	stack<int> pushstack;
	stack<int> popstack;

	void transfer()
	{
		while(!pushstack.empty())
		{
			popstack.push(pushstack.top());
			pushstack.pop();
		}
	}
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        pushstack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(popstack.empty())
			transfer();
		int res=popstack.top();
		popstack.pop();
		return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(popstack.empty())
			transfer();
		return popstack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pushstack.empty()&&popstack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
