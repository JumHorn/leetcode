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
		int f = ++freq[x];
		data[f].push(x);
		if (f > maxFreq)
			maxFreq = f;
	}

	int pop()
	{
		int res = data[maxFreq].top();
		data[maxFreq].pop();
		--freq[res];
		if (data[maxFreq].empty())
			--maxFreq;
		return res;
	}

private:
	int maxFreq;						 //continuous
	unordered_map<int, stack<int>> data; // {freq ,val stack}
	unordered_map<int, int> freq;		 // {val ,freq}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */