#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

class FreqStack
{
public:
	FreqStack()
	{
	}

	void push(int x)
	{
		++freq[x];
		rmstack[freq[x]].push(x);
	}

	int pop()
	{
		int n = rmstack.rbegin()->second.top();
		rmstack.rbegin()->second.pop();
		if (rmstack.rbegin()->second.empty())
			rmstack.erase(freq[n]);
		if (--freq[n] == 0)
			freq.erase(n);
		return n;
	}

private:
	unordered_map<int, int> freq;
	map<int, stack<int>> rmstack;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
